#include "InvKin.h"
#include "LinearPath.h"
#include <Servo.h>
#include <math.h>
#include <Arduino.h>

void currentPos(float x, float y, float z, float cPos[3]){
  cPos[0] = x;
  cPos[1] = y;
  cPos[2] = z;
}

void moveMJT(int duration, float cPos[], float fPos[], Servo s1, Servo s2, Servo s3){
	float steps = 100;
	
	float stepping[3] = {cPos[0], cPos[1], cPos[2]};
	
	float d1 = 0;
	float d2 = 0;
	float d3 = 0;

	float angles[3] = { 0, 0, 0 };

	for (int i = 1; i < duration; i++){
		stepping[0] = cPos[0] + (fPos[0] - cPos[0])*(10.0*pow(1.0*i/duration, 3) - 15.0*pow(1.0*i/duration, 4) + 6.0*pow(1.0*i/duration, 5));
		stepping[1] = cPos[1] + (fPos[1] - cPos[1])*(10.0*pow(1.0*i/duration, 3) - 15.0*pow(1.0*i/duration, 4) + 6.0*pow(1.0*i/duration, 5));
		stepping[2] = cPos[2] + (fPos[2] - cPos[2])*(10.0*pow(1.0*i/duration, 3) - 15.0*pow(1.0*i/duration, 4) + 6.0*pow(1.0*i/duration, 5));
		
		delta_calcInverse(stepping[0], stepping[1], stepping[2], angles[0], angles[1], angles[2]);

		s1.write(-int(angles[0]));
		s2.write(-int(angles[1]));
		s3.write(-int(angles[2]));
    //Serial.println(String(-int(angles[0])));

		delay(1);
	}

	cPos[0] = fPos[0];
	cPos[1] = fPos[1];
	cPos[2] = fPos[2];
}


void move(int duration, float cPos[], float fPos[], Servo s1, Servo s2, Servo s3){
  float steps = 100;
	
	float stepping[3] = {cPos[0], cPos[1], cPos[2]};
	
	float d1 = 0;
	float d2 = 0;
	float d3 = 0;

	float angles[3] = { 0, 0, 0 };

	for (int i = 1; i < duration; i++){
		stepping[0] = cPos[0] + (fPos[0] - cPos[0])*(1.0*i)/duration;
		stepping[1] = cPos[1] + (fPos[1] - cPos[1])*(1.0*i)/duration;
		stepping[2] = cPos[2] + (fPos[2] - cPos[2])*(1.0*i)/duration;
		
		delta_calcInverse(stepping[0], stepping[1], stepping[2], angles[0], angles[1], angles[2]);

		s1.write(-int(angles[0]));
		s2.write(-int(angles[1]));
		s3.write(-int(angles[2]));
    //Serial.println(String(-int(angles[0])));

		delay(1);
	}

	cPos[0] = fPos[0];
	cPos[1] = fPos[1];
	cPos[2] = fPos[2];
}
