#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "movement.h"

#define XSHUT_LEFT 7
#define XSHUT_FRONT 6
#define XSHUT_RIGHT 9
#define SDA 20
#define SCL 21

VL53L0X tof_left;
VL53L0X tof_right;
VL53L0X tof_front;

typedef struct {
  int state, new_state;

  // tes - time entering state
  // tis - time in state
  unsigned long tes, tis;
} fsm_t;

// Input variables
uint8_t S1, prevS1;
uint8_t S2, prevS2;

// Our finite state machines
fsm_t fsm1, fsm2;

unsigned long interval, last_cycle;
unsigned long loop_micros;
uint16_t blink_period;

// Set new state
void set_state(fsm_t& fsm, int new_state)
{
  if (fsm.state != new_state) {  // if the state chnanged tis is reset
    fsm.state = new_state;
    fsm.tes = millis();
    fsm.tis = 0;
  }
}

void sensor_begin(){
  //XSHUT PinMode
  pinMode(XSHUT_FRONT, OUTPUT);
  pinMode(XSHUT_LEFT, OUTPUT);
  pinMode(XSHUT_RIGHT, OUTPUT);
  //Motores PinMode
  pinMode(Motor1_1, OUTPUT);
  pinMode(Motor1_2, OUTPUT);
  pinMode(Motor2_1, OUTPUT);
  pinMode(Motor2_2, OUTPUT);
  pinMode(STBY, OUTPUT);
  //XSHUT LOW
  digitalWrite(XSHUT_FRONT, LOW);
  digitalWrite(XSHUT_LEFT, LOW);
  digitalWrite(XSHUT_RIGHT, LOW);

  Serial.begin(115200);

  //SDA, SCL
  Wire.setSDA(SDA);
  Wire.setSCL(SCL);
  Wire.begin();
  
  //LEFT
  digitalWrite(XSHUT_LEFT, HIGH);
  tof_left.setTimeout(500);
  while (!tof_left.init()) {
    Serial.println(F("Failed to detect and initialize VL53L0X!"));
    delay(100);
  }  
  Serial.println(F("FRONT. Success initialize VL53L0X!"));
  tof_left.startContinuous();
  tof_left.setAddress(0x33);

  //RIGHT
  digitalWrite(XSHUT_RIGHT, HIGH);
  tof_right.setTimeout(500);
  while (!tof_right.init()) {
    Serial.println(F("Failed to detect and initialize VL53L0X!"));
    delay(100);
  }  
  Serial.println(F("FRONT. Success initialize VL53L0X!"));
  tof_right.startContinuous();
  tof_right.setAddress(0x31);

  //FRONT
  digitalWrite(XSHUT_FRONT, HIGH);
  tof_front.setTimeout(500);
  while (!tof_front.init()) {
    Serial.println(F("Failed to detect and initialize VL53L0X!"));
    delay(100);
  }  
  Serial.println(F("FRONT. Success initialize VL53L0X!"));
  tof_front.startContinuous();
}

void sensor_test(){
  Serial.print(tof_left.readRangeContinuousMillimeters());
  if (tof_left.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.print(" ");

  Serial.print(tof_front.readRangeContinuousMillimeters());
  if (tof_front.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.print(" ");

  Serial.print(tof_right.readRangeContinuousMillimeters());
  if (tof_right.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
}
void setup() 
{
  sensor_begin();

  blink_period = 1000 * 1.0/0.33; // In ms

  interval = 40;
  set_state(fsm1, 0);   
}

void loop() 
{
    uint8_t b;
    if (Serial.available()) {  // Only do this if there is serial data to be read
      b = Serial.read();       
      if (b == '-') blink_period = 100 * blink_period / 80;  // Press '-' to decrease the frequency
      if (b == '+') blink_period = 80 * blink_period / 100;  // Press '+' to increase the frequency
    }  
    // To measure the time between loop() calls
    //unsigned long last_loop_micros = loop_micros; 
    
    // Do this only every "interval" miliseconds 
    // It helps to clear the switches bounce effect
    unsigned long now = millis();
    if (now - last_cycle > interval) {
      loop_micros = micros();
      last_cycle = now;

      // FSM processing

      // Update tis for all state machines
      unsigned long cur_time = millis();   // Just one call to millis()
      fsm1.tis = cur_time - fsm1.tes;
      fsm2.tis = cur_time - fsm2.tes; 

      // Calculate next state for the first state machine
      if ((fsm1.state == 0) && tof_right.readRangeContinuousMillimeters() > 350){
        fsm1.new_state = 1;
      }else if((fsm1.state == 1 || fsm1.state == 2) && tof_right.readRangeContinuousMillimeters() > 500) {
        fsm1.new_state = 3;
      }else if(tof_front.readRangeContinuousMillimeters() < 250) {
        fsm1.new_state = 4;
      }else if((fsm1.state == 0 || fsm1.state == 3) && tof_right.readRangeContinuousMillimeters() < 300) {
        fsm1.new_state = 2;
      }else if(fsm1.state == 1 && tof_right.readRangeContinuousMillimeters() < 300) {
        fsm1.new_state = 2;
      }else if(fsm1.state == 2 && tof_right.readRangeContinuousMillimeters() > 350) {
        fsm1.new_state = 1;
      }else if(fsm1.state == 3 && tof_right.readRangeContinuousMillimeters() < 400) {
        fsm1.new_state = 1;
      }else if(fsm1.state == 4 && tof_front.readRangeContinuousMillimeters() > 500) {
        fsm1.new_state = 1;
      }
      // Update the states
      set_state(fsm1, fsm1.new_state);

      // Actions set by the current state of the first state machine
      if (fsm1.state == 1){
        tilt_right(150);
      } else if (fsm1.state == 2){
        tilt_left(150);
      } else if (fsm1.state == 3){
        turn_right();
      } else if (fsm1.state == 4){
        rotate();
      }
    //sensor_test();
    Serial.println(fsm1.state);
  }
}