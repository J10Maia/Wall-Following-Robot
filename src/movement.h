#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>

// Define motor control pins
#define Motor1_1 1
#define Motor1_2 0
#define STBY 4
#define Motor2_1 3
#define Motor2_2 2


// Function declarations
void drive(int speed);
void tilt_right(int speed);
void tilt_left(int speed);
void turn_right();
void rotate();

#endif // MOVEMENT_H
