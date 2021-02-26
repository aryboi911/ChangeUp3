#include "vex.h"
#include "autonMethodLibrary.h"

using namespace vex;

double globalX;
double globalY;
double heading1;
double pi = 3.14159;



// Make a curve towards an object. We will input how far the curve will last, and the speed of the left side and right side
void turnCurve(double targetDistance, double leftSpeed, double rightSpeed){
  double degrees = targetDistance / 0.053;
  FrontLeftDrive.resetRotation();
  BackLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  BackRightDrive.resetRotation();
  while(fabs(FrontLeftDrive.rotation(deg))<degrees){
    float percentTracker = fabs(FrontLeftDrive.rotation(deg)) / degrees;
    if(percentTracker < 0.03){
      int lSpeed = leftSpeed * 3.33 *0.03;
      if(lSpeed < 15 && leftSpeed > 0){
        lSpeed = 15;
      }
      else if(lSpeed > -15 && leftSpeed < 0){
        lSpeed = -15;
      }
      int rSpeed = rightSpeed * 3.33 *0.03;
      if(rSpeed < 15 && rightSpeed > 0){
        rSpeed = 15;
      }
      else if(rSpeed > -15 && rightSpeed < 0){
        rSpeed = -15;
      }
      FrontLeftDrive.spin(fwd, lSpeed * 12 / 25, volt);
      FrontRightDrive.spin(fwd, lSpeed * 12 / 25, volt);
      BackLeftDrive.spin(fwd, rSpeed * 12 / 25, volt);
      BackRightDrive.spin(fwd, rSpeed * 12 / 25, volt);
    }
    else if(percentTracker <= 0.30 && percentTracker >=0.03){
      int lSpeed = leftSpeed * 3.33 *percentTracker;
      if(lSpeed < 15 && leftSpeed > 0){
        lSpeed = 15;
      }
      else if(lSpeed > -15 && leftSpeed < 0){
        lSpeed = -15;
      }
      int rSpeed = rightSpeed * 3.33 *percentTracker;
      if(rSpeed < 15 && rightSpeed > 0){
        rSpeed = 15;
      }
      else if(rSpeed > -15 && rightSpeed < 0){
        rSpeed = -15;
      }
      FrontLeftDrive.spin(fwd, lSpeed * 12 / 75, volt);
      FrontRightDrive.spin(fwd, lSpeed * 12 / 75, volt);
      BackLeftDrive.spin(fwd, rSpeed * 12 / 75, volt);
      BackRightDrive.spin(fwd, rSpeed * 12 / 75, volt);
    }
    else if(percentTracker > 0.30 && percentTracker < 0.70){
      FrontLeftDrive.spin(fwd, leftSpeed* 12 / 100, volt);
      FrontRightDrive.spin(fwd, rightSpeed* 12 / 100, volt);
      BackLeftDrive.spin(fwd, leftSpeed* 12 / 100, volt);
      BackRightDrive.spin(fwd, rightSpeed* 12 / 100, volt);
    }
    else if(percentTracker >= 0.70 ){
      int lSpeed = (leftSpeed - (percentTracker * leftSpeed)) * 3.33;
      if(lSpeed <= leftSpeed * 3/16 && leftSpeed > 0){
        lSpeed = leftSpeed*3/16;
      }
      else if(lSpeed >= leftSpeed *3/16 && leftSpeed < 0){
        lSpeed = leftSpeed*3/16;
      }
      if(lSpeed < 15 && leftSpeed > 0){
        lSpeed = 15;
      }
      else if(lSpeed > -15 && leftSpeed < 0){
        lSpeed = -15;
      }
      int rSpeed = (rightSpeed - (percentTracker * rightSpeed)) * 3.33;
      if(rSpeed <= rightSpeed * 3/16 && rightSpeed > 0){
        rSpeed = rightSpeed*3/16;
      }
      else if(rSpeed >= rightSpeed *3/16 && rightSpeed < 0){
        rSpeed = rightSpeed*3/16;
      }
      if(rSpeed < 15 && rightSpeed > 0){
        rSpeed = 15;
      }
      else if(rSpeed > -15 && rightSpeed < 0){
        rSpeed = -15;
      }
      FrontLeftDrive.spin(fwd, lSpeed* 12 / 50, volt);
      FrontRightDrive.spin(fwd, rSpeed* 12 / 50, volt);
      BackLeftDrive.spin(fwd, lSpeed* 12 / 50, volt);
      BackRightDrive.spin(fwd, rSpeed* 12 / 50, volt);
    }
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

// This is so we can go backwards a certain distance will outtaking balls. This will be used when backing away from a goal with
// balls of the opposing alliance in our bot. This gets rid of them while backing up
void dropLinearEquation(double targetDistance, int maxSpeed){
  double degrees = targetDistance / 0.053;
  FrontLeftDrive.resetRotation();
  BackLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  BackRightDrive.resetRotation();
  while(fabs(FrontLeftDrive.rotation(deg))<degrees){
    float percentTracker = fabs(FrontLeftDrive.rotation(deg)) / degrees;
    if(percentTracker < 0.03){
      int speed = maxSpeed * 3.33 *0.03;
      if(speed < 15 && maxSpeed > 0){
        speed = 15;
      }
      else if(speed > -15 && maxSpeed < 0){
        speed = -15;
      }
      FrontLeftDrive.spin(fwd, speed, pct);
      FrontRightDrive.spin(fwd, speed, pct);
      BackLeftDrive.spin(fwd, speed, pct);
      BackRightDrive.spin(fwd, speed, pct);
    }
    else if(percentTracker <= 0.30 && percentTracker >=0.03){
      int speed = percentTracker * maxSpeed * 3.33;
      if(speed <= 15 && maxSpeed > 0){
        speed = 15;
      }
      else if(speed > -15 && maxSpeed < 0){
        speed = -15;
      }
      FrontLeftDrive.spin(fwd, speed, pct);
      FrontRightDrive.spin(fwd, speed, pct);
      BackLeftDrive.spin(fwd, speed, pct);
      BackRightDrive.spin(fwd, speed, pct);
    }
    else if(percentTracker > 0.30 && percentTracker < 0.70){
      int speed = maxSpeed;
      FrontLeftDrive.spin(fwd, speed, pct);
      FrontRightDrive.spin(fwd, speed, pct);
      BackLeftDrive.spin(fwd, speed, pct);
      BackRightDrive.spin(fwd, speed, pct);
      Indexer.spin(reverse, 100, pct);
      LeftIntake.spin(reverse, 100, pct);
      RightIntake.spin(reverse, 100, pct);
    }
    else if(percentTracker >= 0.70 ){
      int speed = (maxSpeed - (percentTracker * maxSpeed)) * 3.33;
      if(speed <= maxSpeed * 3/16 && maxSpeed > 0){
        speed = maxSpeed*3/16;
      }
      else if(speed >= maxSpeed *3/16 && maxSpeed < 0){
        speed = maxSpeed*3/16;
      }
      if(speed < 15 && maxSpeed > 0){
        speed = 15;
      }
      else if(speed > -15 && maxSpeed < 0){
        speed = -15;
      }
      FrontLeftDrive.spin(fwd, speed, pct);
      FrontRightDrive.spin(fwd, speed, pct);
      BackLeftDrive.spin(fwd, speed, pct);
      BackRightDrive.spin(fwd, speed, pct);
      Indexer.spin(reverse, 100, pct);
      LeftIntake.spin(reverse, 100, pct);
      RightIntake.spin(reverse, 100, pct);
    }
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
  Indexer.stop(brake);
  RightIntake.stop(brake);
  LeftIntake.stop(brake);
}

//This is a base function always running in the background, it helps provide coordinates for the goTo and turn functions.
void positionTracking(){
  globalX = 36;
  globalY = 0;
  BackLeftDrive.resetRotation();
  BackRightDrive.resetRotation();
  while (true){
    double initialHeading = (450-(int)Inertial.heading())%360;
    double initialRadian = initialHeading*(pi/180);
    double initialX = globalX;
    double initialY = globalY;
    double initialLeft = BackLeftDrive.rotation(deg);
    double initialRight = BackRightDrive.rotation(deg);
    wait(5, msec);
    double leftChange = (BackLeftDrive.rotation(deg)- initialLeft)*0.05759586531;
    double rightChange = (BackRightDrive.rotation(deg) - initialRight)*0.05759586531;
    double movement = (leftChange + rightChange) / 2;
    double changeX = (cos(initialRadian))*movement;
    double changeY = (sin(initialRadian))*movement;
    globalX = initialX + changeX;
    globalY = initialY + changeY;
    heading1 = initialHeading;
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("X: ");
    Brain.Screen.print(globalX);
    Brain.Screen.print("     Y: ");
    Brain.Screen.print(globalY);
    Brain.Screen.print("     H: ");
    Brain.Screen.print(initialHeading);
    Brain.Screen.newLine();
    Brain.Screen.print("BL: ");
    Brain.Screen.print(BackLeftDrive.rotation(deg));
    Brain.Screen.print("     BR: ");
  }
}

/*Go to function. This function is used to move the robot to a certain point The robot will turn to face the point and go ther
  automatically. finalX is the x valie of the point we have to go to. final Y is the same but for the Y coordinate. For now, 
  final heading will always be 361 until I can get a curve function working, turnDirection is the direction we want the robot
  to turn towards when it turns to face the point we want it to go to. -1 is turn left and 1 is turn right. kP and kD are values
  used in the PD function to adjust the speed. We usually start with 0.4 and 0.6 and then guess and check until we get the speeds
  we want. minSpeed is the minimum speed the robot shoud travel at any time, usuallyy set at 15 but can be changed based on 
  circumstances. Error margin is the "accuracy" meter. This tells the function how close is good enough. Usually set at about
  0.25 inches but again, can be adjusted based on circumstances. (Final heading has since been eliminated until I make a curve
  function.)
 */

void goTo(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin){
  int sign1;
  int sign2;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if(changeX < 0){sign1 = -1;} else if(changeX > 0){sign1 = 1;}
  if(changeY < 0){sign2 = -1;} else if(changeY > 0){sign2 = 1;}
  int fsign1 = sign1;
  int fsign2 = sign2;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX)*(180/pi);
  if (deviationHeading < 0){ deviationHeading = deviationHeading * -1;}
  if(changeY > 0 && changeX > 0){  
    turnHeading = deviationHeading;
  }
  if(changeY > 0 && changeX < 0){
    turnHeading = 180 - deviationHeading;
  }
  if(changeY < 0 && changeX < 0){
    turnHeading = 180 + deviationHeading;
  }
  if(changeY < 0 && changeX > 0){
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1){
    turnLeft(turnHeading);
  }
  if (turnDirection == 1){
    turnRight(turnHeading);
  }
  wait(200, msec);
  double errorDerivative = -1;
  while(error > errorMargin && sign1 == fsign1 && sign2 == fsign2){
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error-prevError)/(Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP*error) + (kD*errorDerivative);
    if(speed < 0){
      speed = speed *-1;
    }
    if (minSpeed > speed){
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed*12/100, volt);
    BackLeftDrive.spin(fwd, speed*12/100, volt);
    FrontRightDrive.spin(fwd, speed*12/100, volt);
    BackRightDrive.spin(fwd, speed*12/100, volt);
    wait(15, msec);
    if(changeX < 0){fsign1 = -1;} else if(changeX > 0){fsign1 = 1;}
    if(changeY < 0){fsign2 = -1;} else if(changeY > 0){fsign2 = 1;}
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void turnLeft(int degrees){
  int finalHeading = (450 - degrees)%360;
  double changeHeading = finalHeading - Inertial.heading();
  if(changeHeading > 0){ changeHeading = changeHeading - 360;}
  float origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  float kp = 0.0015 * changeHeading + 0.035;
  if(kp < 0.115){kp = 0.115;}
  float kd = 90;
  float previousAngleError;
  float angleDerivative;
  float turnV = 1.5;
  int flatTurnValue = 1;  
  float angleError = Inertial.rotation(deg) - changeHeading;
  previousAngleError = angleError;
  while(Inertial.rotation(deg) > (changeHeading)){
    angleError = Inertial.rotation(deg) - changeHeading;
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError * kp) - (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}
    if(turnV < 7){turnV = 7;}


    BackLeftDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    FrontLeftDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    BackRightDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    FrontRightDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    wait(10, msec);
  }
  /*
  finalHeading = (450 - degrees)%360;
  changeHeading = finalHeading - Inertial.heading();
  if(changeHeading > 0){ changeHeading = changeHeading - 360;}
  origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  kp = 0.125;
  kd = 60;
  turnV = 1.5;
  flatTurnValue = 2;  
  angleError = Inertial.rotation(deg) - changeHeading;
  previousAngleError = angleError;
  while(Inertial.rotation(deg) > changeHeading){
    angleError = Inertial.rotation(deg) - changeHeading;
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError * kp) - (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}


    BackLeftDrive.spin(fwd, -turnV * 2, pct);
    FrontLeftDrive.spin(fwd, -turnV * 2, pct);
    BackRightDrive.spin(fwd, turnV * 2, pct);
    FrontRightDrive.spin(fwd, turnV * 2, pct);
  }
  */
  BackLeftDrive.spin(fwd, 20, pct);
  FrontLeftDrive.spin(fwd, 20, pct);
  BackRightDrive.spin(fwd, -20, pct);
  FrontRightDrive.spin(fwd, -20, pct);
  wait(fabs(5/3*origChangeHeading), msec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);

}
  

void turnRight(int degrees){
  int finalHeading = (450 - degrees);
  if(finalHeading > 360){ finalHeading = finalHeading - 360;}
  double changeHeading = finalHeading - Inertial.heading();
  if(changeHeading < 0){ changeHeading = changeHeading + 360;}
  float origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  float kp = 0.0015 * changeHeading + 0.025;
  if(kp < 0.115){kp = 0.115;}
  float kd = 10;
  float previousAngleError;
  float angleDerivative;
  float turnV = 1.5;
  int flatTurnValue = 1;  
  float angleError = changeHeading - Inertial.rotation(deg);
  previousAngleError = angleError;
  while(Inertial.rotation(deg) < (changeHeading-5)){
    angleError = changeHeading - Inertial.rotation(deg);
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError*kp) + (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}
    if(turnV < 7){turnV = 7;}
    
    BackLeftDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    FrontLeftDrive.spin(fwd, turnV * 2 * 12 / 100, volt);
    BackRightDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    FrontRightDrive.spin(fwd, -turnV * 2 * 12 / 100, volt);
    wait(10, msec);
  }
  /*
  finalHeading = (450 - degrees);
  if(finalHeading > 360){ finalHeading = finalHeading - 360;}
  changeHeading = finalHeading - Inertial.heading();
  if(changeHeading < 0){ changeHeading = changeHeading + 360;}
  origChangeHeading = changeHeading;
  Inertial.resetRotation();
  wait(30, msec);
  kp = 0.125;
  kd = 10;
  previousAngleError;
  angleDerivative;
  turnV = 1.5;
  flatTurnValue = 1;  
  angleError = changeHeading - Inertial.rotation(deg);
  previousAngleError = angleError;
  while(Inertial.rotation(deg) < changeHeading){
    angleError = changeHeading - Inertial.rotation(deg);
    angleDerivative = angleError - previousAngleError;
    turnV = (angleError*kp) + (angleDerivative * kd) + flatTurnValue;
    previousAngleError = angleError;
    if(turnV > 50){turnV = 50;}

    BackLeftDrive.spin(fwd, turnV * 2, pct);
    FrontLeftDrive.spin(fwd, turnV * 2, pct);
    BackRightDrive.spin(fwd, -turnV * 2, pct);
    FrontRightDrive.spin(fwd, -turnV * 2, pct);
  }
  */
  BackLeftDrive.spin(fwd, -20, pct);
  FrontLeftDrive.spin(fwd, -20, pct);
  BackRightDrive.spin(fwd, 20, pct);
  FrontRightDrive.spin(fwd, 20, pct);

  wait(5/3*origChangeHeading, msec);
  
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
}

void backLinear(double targetDistance, int minSpeed, double kP){
  FrontLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  double degrees = targetDistance/0.03599741582;
  while(FrontLeftDrive.rotation(deg) > degrees){
    double inchesLeft = (degrees - FrontLeftDrive.rotation(deg))*0.03599741582;
    double speed = inchesLeft *kP;
    if (speed > minSpeed){
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void backCurve(double targetDistance, int minSpeed, double kP, int leftSpeed, int rightSpeed){
  FrontLeftDrive.resetRotation();
  FrontRightDrive.resetRotation();
  double degrees = targetDistance/0.03599741582;
  double factor = rightSpeed / leftSpeed;
  while(FrontLeftDrive.rotation(deg) > degrees){
    double inchesLeft = (degrees - FrontLeftDrive.rotation(deg))*0.03599741582;
    double speed = inchesLeft *kP;
    if (speed > minSpeed){
      speed = minSpeed;
    }
    double rSpeed = factor * speed;
    FrontLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, rSpeed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, rSpeed, pct);
    wait(10, msec);
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void IgnoreX(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin){
  int sign2;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if(changeY < 0){sign2 = -1;} else if(changeY > 0){sign2 = 1;}
  int fsign2 = sign2;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX)*(180/pi);
  if (deviationHeading < 0){ deviationHeading = deviationHeading * -1;}
  if(changeY > 0 && changeX > 0){  
    turnHeading = deviationHeading;
  }
  if(changeY > 0 && changeX < 0){
    turnHeading = 180 - deviationHeading;
  }
  if(changeY < 0 && changeX < 0){
    turnHeading = 180 + deviationHeading;
  }
  if(changeY < 0 && changeX > 0){
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1){
    turnLeft(turnHeading);
  }
  if (turnDirection == 1){
    turnRight(turnHeading);
  }
  wait(350, msec);
  double errorDerivative = -1;
  while(error > errorMargin && sign2 == fsign2){
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error-prevError)/(Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP*error) + (kD*errorDerivative);
    if(speed < 0){
      speed = speed *-1;
    }
    if (minSpeed > speed){
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
    if(changeY < 0){fsign2 = -1;} else if(changeY > 0){fsign2 = 1;}
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}

void IgnoreY(double finalX, double finalY, int turnDirection, double kP, double kD, 
              double minSpeed, double errorMargin){
  int sign1;
  double changeX = finalX - globalX;
  double changeY = finalY - globalY;
  if(changeX < 0){sign1 = -1;} else if(changeX > 0){sign1 = 1;}
  int fsign1 = sign1;
  double turnHeading;
  double error = (sqrt(changeX * changeX + changeY * changeY));
  double prevError = (sqrt(changeX * changeX + changeY * changeY));
  double deviationHeading = atan(changeY / changeX)*(180/pi);
  if (deviationHeading < 0){ deviationHeading = deviationHeading * -1;}
  if(changeY > 0 && changeX > 0){  
    turnHeading = deviationHeading;
  }
  if(changeY > 0 && changeX < 0){
    turnHeading = 180 - deviationHeading;
  }
  if(changeY < 0 && changeX < 0){
    turnHeading = 180 + deviationHeading;
  }
  if(changeY < 0 && changeX > 0){
    turnHeading = 360 - deviationHeading;
  }
  if (turnDirection == -1){
    turnLeft(turnHeading);
  }
  if (turnDirection == 1){
    turnRight(turnHeading);
  }
  wait(350, msec);
  double errorDerivative = -1;
  while(error > errorMargin && sign1 == fsign1){
    changeX = finalX - globalX;
    changeY = finalY - globalY;
    error = (sqrt(changeX * changeX + changeY * changeY));
    errorDerivative = (error-prevError)/(Brain.timer(msec));
    Brain.resetTimer();
    prevError = error;
    double speed = (kP*error) + (kD*errorDerivative);
    if(speed < 0){
      speed = speed *-1;
    }
    if (minSpeed > speed){
      speed = minSpeed;
    }
    FrontLeftDrive.spin(fwd, speed, pct);
    BackLeftDrive.spin(fwd, speed, pct);
    FrontRightDrive.spin(fwd, speed, pct);
    BackRightDrive.spin(fwd, speed, pct);
    wait(10, msec);
    if(changeX < 0){fsign1 = -1;} else if(changeX > 0){fsign1 = 1;}
  }
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
}