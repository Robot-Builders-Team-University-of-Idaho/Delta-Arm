<<<<<<< HEAD
#include "InvKin.h"
#include <Servo.h>
#include <math.h>

const float e = 25;     // end effector
const float f = 100.0;     // base
const float re = 90.0;
const float rf = 150.0;

// trigonometric constants
const float sqrt3 = 1.73205;
const float pi = 3.141592653;    // PI
const float sin120 = sqrt3 / 2.0;
const float cos120 = -0.5;
const float tan60 = sqrt3;
const float sin30 = 0.5;
const float tan30 = 1 / sqrt3;

int delta_calcAngleYZ(float x0, float y0, float z0, float& theta) {
    float y1 = -0.5 * 0.57735 * f; // f/2 * tg 30
    y0 -= 0.5 * 0.57735 * e;    // shift center to edge
    // z = a + b*y
    float a = (x0 * x0 + y0 * y0 + z0 * z0 + rf * rf - re * re - y1 * y1) / (2 * z0);
    float b = (y1 - y0) / z0;
    // discriminant
    float d = -(a + b * y1) * (a + b * y1) + rf * (b * b * rf + rf);
    if (d < 0) return -1; // non-existing point
    float yj = (y1 - a * b - sqrt(d)) / (b * b + 1); // choosing outer point
    float zj = a + b * yj;
    theta = 180.0 * atan(-zj / (y1 - yj)) / pi + ((yj > y1) ? 180.0 : 0.0);
    return 0;
}

int delta_calcInverse(float x0, float y0, float z0, float& theta1, float& theta2, float& theta3) {
    theta1 = theta2 = theta3 = 0;
    int status = delta_calcAngleYZ(x0, y0, z0, theta1);
    if (status == 0) status = delta_calcAngleYZ(x0 * cos120 + y0 * sin120, y0 * cos120 - x0 * sin120, z0, theta2);  // rotate coords to +120 deg
    if (status == 0) status = delta_calcAngleYZ(x0 * cos120 - y0 * sin120, y0 * cos120 + x0 * sin120, z0, theta3);  // rotate coords to -120 deg
    return status;
}

=======
#include "InvKin.h"
#include <Servo.h>
#include <math.h>

const float e = 25;     // end effector
const float f = 100.0;     // base
const float re = 90.0;
const float rf = 150.0;

// trigonometric constants
const float sqrt3 = 1.73205;
const float pi = 3.141592653;    // PI
const float sin120 = sqrt3 / 2.0;
const float cos120 = -0.5;
const float tan60 = sqrt3;
const float sin30 = 0.5;
const float tan30 = 1 / sqrt3;

int delta_calcAngleYZ(float x0, float y0, float z0, float& theta) {
    float y1 = -0.5 * 0.57735 * f; // f/2 * tg 30
    y0 -= 0.5 * 0.57735 * e;    // shift center to edge
    // z = a + b*y
    float a = (x0 * x0 + y0 * y0 + z0 * z0 + rf * rf - re * re - y1 * y1) / (2 * z0);
    float b = (y1 - y0) / z0;
    // discriminant
    float d = -(a + b * y1) * (a + b * y1) + rf * (b * b * rf + rf);
    if (d < 0) return -1; // non-existing point
    float yj = (y1 - a * b - sqrt(d)) / (b * b + 1); // choosing outer point
    float zj = a + b * yj;
    theta = 180.0 * atan(-zj / (y1 - yj)) / pi + ((yj > y1) ? 180.0 : 0.0);
    return 0;
}

int delta_calcInverse(float x0, float y0, float z0, float& theta1, float& theta2, float& theta3) {
    theta1 = theta2 = theta3 = 0;
    int status = delta_calcAngleYZ(x0, y0, z0, theta1);
    if (status == 0) status = delta_calcAngleYZ(x0 * cos120 + y0 * sin120, y0 * cos120 - x0 * sin120, z0, theta2);  // rotate coords to +120 deg
    if (status == 0) status = delta_calcAngleYZ(x0 * cos120 - y0 * sin120, y0 * cos120 + x0 * sin120, z0, theta3);  // rotate coords to -120 deg
    return status;
}

>>>>>>> 8cc71c1f1aa978e205888081b732ee4624109bca
