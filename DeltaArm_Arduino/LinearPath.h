#ifndef LINEARPATH_H
#define LINEARPATH_H

#include <Servo.h>
#include <math.h>
#include <Arduino.h>

void currentPos(float x, float y, float z, float cPos[3]);
void moveMJT(int duration_in_milliseconds, float cPos[], float fPos[], Servo s1, Servo s2, Servo s3);
void move(int duration, float cPos[], float fPos[], Servo s1, Servo s2, Servo s3);

#endif