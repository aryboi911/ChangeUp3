#include "autonMethodLibrary.h"
#include "vex.h"

void leftAndCenter(){
  
}

void Left(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(15, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-9, -40, 3);
}

void leftAndMiddle(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -68);
  
  IgnoreX(53.5, 1.25, -1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-10.5, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);
}

void rightAndMiddle(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(23.5, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Sorter.stop(hold);
  wait(1,sec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(58, -85, -48);
  
  Indexer.spin(fwd, 13, volt);
  IgnoreX(68, -1.25, 1, 2.2, 60, 45, 0.5);
  
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-10.5, -40, 3);

}

void Right(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(23.5, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Sorter.stop(hold);
  wait(1,sec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-11.25, -25, 5);
}

void progSkills(){
  
  // 36, 27
  Indexer.spin(fwd, 13, volt);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(36, 15, 0, 2.3, 60, 45, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  // 11, 4.5
  
  goTo(14, 0, -1, 2.1, 60, 45, 0.5);
  //decrease y
  wait(200,msec);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(200, msec);
  Indexer.stop(brake);
  wait(200, msec);
  Sorter.stop(hold);
  wait(400, msec);
  
  
  //2nd
  backLinear(-11.25, -45, 2);
  
  
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(15.25, 54, 1, 1.8, 60, 35, 0.5);
  wait(200, msec);
 //increase y
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  
  IgnoreY(15.75, 60, -1, 2.1, 60, 35, 0.5);

  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  //increase y
  Sorter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Sorter.stop(hold);
  Indexer.spin(fwd, 100, pct);
  wait(400, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  
  //3rd
  backLinear(-7.5, -20, 2);
  
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(29.5, 98, 1, 2.1, 60, 35, 0.5);
  backLinear(-1.5, -40, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  
  IgnoreY(14., 119, -1, 2.1, 60, 40, 0.5);
  //lower x
  wait(500, msec);
  Sorter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Sorter.stop(hold);
  wait(400, msec);

  //14.75, 114.8

  setCoordinates(1);

  
  
  //4th
  backLinear(-7.5, -25, 2);
  
  //Increase X
  Indexer.spin(fwd, 100, pct);
  IgnoreY(70.5, 108, 1, 1.8, 60, 30, 0.5);
  Indexer.stop(brake);
  RightIntake.stop(brake);
  LeftIntake.stop(brake);
  //Increase X
  Indexer.stop(brake);
  IgnoreX(70.5, 110.5, -1, 2.1, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 13, volt);
  wait(600, msec);
  Sorter.stop(hold);
  wait(400, msec);
  
  
  //70, 111.75
  
  //5th
  backLinear(-2.25, -20, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct); 
  Indexer.spin(fwd, 100, pct);
  IgnoreY(112, 116.5, 1, 1.6, 60, 25, 0.5);
  Indexer.stop(brake);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  goTo(124, 118, -1, 3, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 13, volt);
  wait(600, msec);
  Sorter.stop(hold);
  

  
  // 6th
  backLinear(-15, -40, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct); 
  Indexer.spin(fwd, 100, pct);
  IgnoreX(107, 64, 1, 1.8, 60, 30, 0.5);
  IgnoreY(123, 61, -1, 1.8, 60, 30, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 100, pct);
  wait(150, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Sorter.stop(brake);
  
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  
  

  //127,62.5

  setCoordinates(2);

  
  // 7th

  backLinear(-8, -30, 2);
  
  Indexer.spin(fwd, 100, pct);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(113.5, 19.5, 1, 2.1, 60, 35, 0.5);
  backLinear(-8, -20, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  IgnoreY(128, 5, -1, 3, 60, 35, 0.5);
  //lower x
  Sorter.spin(fwd, 13, volt);
  wait(200, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Sorter.stop(hold);
  wait(400, msec);

  
  
  //8th
  backLinear(-8, -30, 2);
  IgnoreY(80, 12, 1, 2.1, 60, 40, 0.5);
  IgnoreX(79, 6.5, -1, 2.2, 60, 40, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 13, volt);
  wait(600, msec);
  Sorter.stop(hold);


  //9th

  backLinear(-4, -30, 3);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  IgnoreX(69, 36.5, 1, 2.2, 60, 40, 0.5);

  wait(200, msec);

  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  FrontRightDrive.spin(fwd, 45, pct);
  BackRightDrive.spin(fwd, 45, pct);
  wait(30, msec);
  BackRightDrive.spin(forward, 45, pct);
  FrontLeftDrive.spin(fwd, 45, pct);

  wait(600, msec);
  
  BackLeftDrive.stop(brake);
  BackRightDrive.stop(brake);
  FrontLeftDrive.stop(brake);
  FrontRightDrive.stop(brake);

  wait(400, msec);

  BackLeftDrive.spin(fwd, -25, pct);
  BackRightDrive.spin(fwd, -25, pct);
  FrontRightDrive.spin(forward, -25, pct);
  FrontLeftDrive.spin(fwd, -25, pct);

  wait(800, msec);

  BackLeftDrive.spin(fwd, 30, pct);
  BackRightDrive.spin(fwd, 40, pct);
  FrontRightDrive.spin(fwd, 40, pct);
  FrontLeftDrive.spin(fwd, 30, pct);

  wait(1000, msec);
  BackLeftDrive.spin(fwd, 30, pct);
  FrontLeftDrive.spin(fwd, 30, pct);

  wait(400, msec);
  
  BackLeftDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  LeftIntake.stop(coast);
  RightIntake.stop(coast);
  wait(100, msec);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);


  wait(5, sec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);

}

void homeRow(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  wait(200, msec);
  turnCurve(15, 25, 50);
  wait(200, msec);
  Sorter.spin(fwd, 100, pct);
  int ballCount = 0;
  BackLeftDrive.spin(fwd, 3, pct);
  BackRightDrive.spin(fwd, 3, pct);
  FrontLeftDrive.spin(fwd, 3, pct);
  FrontRightDrive.spin(fwd, 3, pct);
  int timer1=0;
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()&&timer1<300){
        wait(5, msec);
        timer1++;
      }
    }
    wait(5, msec);
  }

  wait(20, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(600, msec);  
  
  Indexer.stop(brake);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-2.4, -30, 3);
  
  turnCurve(45, -50, -68);
  ballCount = 0;
  
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(64, 3, -1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  timer1 = 0;
  wait(100, msec);
  BackLeftDrive.spin(fwd, 1, pct);
  BackRightDrive.spin(fwd, 1, pct);
  FrontLeftDrive.spin(fwd, 1, pct);
  FrontRightDrive.spin(fwd, 1, pct);
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(20, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(200, msec);  
  
  Indexer.spin(reverse, 50, pct);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);


  backLinear(-11, -40, 3);
  
  

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  ballCount = 0;

  IgnoreY(128, -6, -1, 1.65, 60, 30, 0.5);

  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);

  wait(100, msec);
  timer1 = 0;
  while (ballCount < 2 && timer1 < 600){
    timer1++;
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(5, msec);
      }
    }
    wait(5, msec);
  }
  wait(50, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(100, msec);

  Sorter.stop(hold);
  Indexer.spin(reverse, 100, pct);
  backLinear(-14.4, -40, 3);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
  

}

void homeRowRight(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 60, pct);
  wait(300, msec);
  turnCurve(24.6, 80, 20);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  Sorter.spin(fwd, 13, volt);
  // wait(100, msec);
  wait(800, msec);
  Sorter.stop(hold);
  Indexer.stop(brake);

  wait(300, msec);
  backLinear(-8, -40, 3);
  // wait(100, msec);
  // wait(300, msec);

  
  /*
  turnCurve(61, -80, -50);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 13, volt);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(68, 1.5, 1, 2.2, 60, 45, 0.5);

  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  ballCount = 0;
  while(ballCount < 2){
    int prevBallCount = ballCount;
    if(LineSensor.value(pct) < 56){
      ballCount++;
    }
    if(prevBallCount < ballCount){
      wait(125, msec);
    }
  }
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(100, msec);
  Indexer.spin(reverse, 30, pct);
  wait(200, msec);
  Sorter.stop(brake);

  backLinear(-14, -30, 3);
  Sorter.spin(fwd, 100, pct);
  wait(500, msec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);

  IgnoreY(127.75, 20.5, 1, 1.75, 60, 35, 0.5);
  Sorter.spin(fwd, 100, pct);

  wait(500, msec);
  
  // wait(100, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(200, msec);
  backLinear(-12, -40, 3);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
  */
  
}

void rightAndSide(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  wait(300, msec);
  turnCurve(24.6, 70, 28);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 13, volt);
  wait(100, msec);
  Indexer.stop(brake);
  wait(300, msec);
  Sorter.stop(brake);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-1.6, -25, 2);
  Indexer.spin(fwd, 100, pct);

 

  IgnoreX(6.75, -27, -1, 2.2, 60, 35, 0.5);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  BackLeftDrive.spin(fwd, 100, pct);
  FrontLeftDrive.spin(fwd, 100, pct);
  FrontRightDrive.spin(fwd, 85, pct);
  BackRightDrive.spin(fwd, 85, pct);
  wait(500, msec);

  BackLeftDrive.spin(fwd, 10, pct);
  FrontLeftDrive.spin(fwd, 10, pct);
  FrontRightDrive.spin(fwd, 10, pct);
  BackRightDrive.spin(fwd, 10, pct);
  int tracker = 0;
  int ballCount = 0;
  while (ballCount < 1 && tracker < 300){
    if(Limit.pressing()){
      ballCount++;
      while(Limit.pressing()){
        wait(10, msec);
      }
    }
    wait(10, msec);
    tracker++;
  }
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);

  wait(300, msec);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);

  wait(800, msec);
  Sorter.spin(reverse, 100, pct);

  wait(800, msec);
  Sorter.spin(fwd, 100, pct);

  wait(500, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-8, -40, 4);
  

}

void Side(){
  
}

void Center(){
  Inertial.setHeading(270, deg);
  wait(2, sec);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreY(0, 0, 0, 2.2, 60, 45, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  IgnoreX(0, 29, 1, 2.2, 60, 45, 0.5);

  IgnoreY(-18, 31.5, -1, 2.2, 60, 45, 70);
  wait(8, sec);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  BackLeftDrive.spin(fwd, 100, pct);
  FrontLeftDrive.spin(fwd, 100, pct);
  FrontRightDrive.spin(fwd, 100, pct);
  BackRightDrive.spin(fwd, 100, pct);

  wait(500, msec);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);

  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(brake);

  LeftIntake.spin(fwd, -100, pct);
  RightIntake.spin(fwd, -100, pct);

  BackLeftDrive.spin(fwd, -100, pct);
  FrontLeftDrive.spin(fwd, -100, pct);
  FrontRightDrive.spin(fwd, -100, pct);
  BackRightDrive.spin(fwd, -100, pct);

  wait(500, msec);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);



  wait(5, sec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
}

void OrcahBlue(){
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 56);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -68);
  
  IgnoreX(53.5, 1.25, -1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-11.2, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);

  IgnoreY(129.75, -39, -1, 1.65, 60, 30, 0.5);

  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  wait(1, sec);
  backLinear(-19.6, -40, 3);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
  
}

