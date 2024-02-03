#include "movement.h"

void drive(int speed) {
    digitalWrite(STBY, HIGH);
    // Motor A Functioning
    analogWrite(Motor1_1, speed);
    analogWrite(Motor1_2, 0);
    // Motor B Functioning
    analogWrite(Motor2_1, speed);
    analogWrite(Motor2_2, 0);
}

void tilt_right(int speed){
    digitalWrite(STBY, HIGH);
    // Motor A Functioning
    analogWrite(Motor1_1, speed);
    analogWrite(Motor1_2, 0);
    // Motor B Functioning
    analogWrite(Motor2_1, speed - 20);
    analogWrite(Motor2_2, 0);
}

void tilt_left(int speed){
    digitalWrite(STBY, HIGH);
    // Motor A Functioning
    analogWrite(Motor1_1, speed - 20);
    analogWrite(Motor1_2, 0);
    // Motor B Functioning
    analogWrite(Motor2_1, speed);
    analogWrite(Motor2_2, 0);
}

void turn_right(){
    digitalWrite(STBY, HIGH);
    // Motor A Functioning
    analogWrite(Motor1_1, 120);
    analogWrite(Motor1_2, 0);
    // Motor B Functioning
    analogWrite(Motor2_1, 20);
    analogWrite(Motor2_2, 0);
}

void rotate(){
    digitalWrite(STBY, HIGH);
    // Motor A Functioning
    analogWrite(Motor1_1, 0);
    analogWrite(Motor1_2, 0);
    // Motor B Functioning
    analogWrite(Motor2_1, 100);
    analogWrite(Motor2_2, 0);
}