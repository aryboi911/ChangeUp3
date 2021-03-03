#ifndef AUTONMETHODLIBRARY_H
#define AUTONMETHODLIBRARY_H

void testLinearEquation(double targetDistance, int maxSpeed);
void turnRight(int degrees);
void turnLeft(int degrees);
void turnCurve(double targetDistance, double leftSpeed, double rightSpeed);
void turnLeft1(int degrees);
void dropLinearEquation(double targetDistance, int maxSpeed);
void positionTracking();
void goTo(double finalX, double finalY, int turnDirection, double kP, double kD, double minSpeed, double errorMargin);
void backLinear(double targetDistance, int minSpeed, double kP);
void IgnoreX(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
void IgnoreY(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin);
#endif