#include <Servo.h>
#include "InvKin.h"
#include "LinearPath.h"


Servo s1, s2, s3;
int startpos = 45;
float cPos[3];
float starting_angles[3];

float time = 0;
float r = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(3);
  s1.attach(8);
  s2.attach(9);
  s3.attach(10);
  
  float cPos[3] = {0, 0, 160};
  delta_calcInverse(cPos[0], cPos[1], cPos[2], starting_angles[0], starting_angles[1], starting_angles[2]);
  Serial.println(-int(starting_angles[0]));
  s1.write(-int(starting_angles[0]));
  s2.write(-int(starting_angles[1]));
  s3.write(-int(starting_angles[2]));

  delay(5000);
  float fPos[3] = {r * cos(time), r * sin(time), 160};
  moveMJT(1000, cPos, fPos, s1, s2, s3);
  delay(1000);
}

void loop() {
  float fPos[3] = {r * cos(time), r * sin(time), 160};
  move(5, cPos, fPos, s1, s2, s3);
  time += 0.1;
  Serial.println(time);
}
