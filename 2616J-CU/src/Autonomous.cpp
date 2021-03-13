#include "autonMethodLibrary.h"
#include "vex.h"

void leftAndCenter(){
  Inertial.setHeading(180, degrees);
  wait(2000, msec);
  backLinear(-8, -25, 3);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  goTo(-13, -18.2, 1, 2.2, 60, 25, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 100, pct);
  wait(300, msec);
  Sorter.stop(hold);
  wait(200, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-15, -25, 5);
  Indexer.stop(brake);
  LeftIntake.spin(forward, 100, pct);
  RightIntake.spin(forward, 100, pct);
  goTo(15.25, 36, 1, 2.5, 100, 25, 0.5);
  Indexer.spin(fwd, 100, pct);


  backLinear(-7.5, -25, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  goTo(19.5, 37.5, 1, 2, 100, 25, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Sorter.stop(hold);
  backLinear(-15, -25, 3);
  Indexer.stop(brake);
}

void Left(){
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 70);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-12, -40, 3);
}

void leftAndMiddle(){
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 70);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -85);
  
  IgnoreX(63.5, 1.25, -1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-14, -40, 3);
}

void rightAndMiddle(){
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(21, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(58, -85, -60);
  
  IgnoreX(63.5, -1.25, 1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-14, -40, 3);
}

void Right(){
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(21, 70, 20);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  backLinear(-15, -25, 5);
}

void progSkills(){
  
  Inertial.setHeading(0, degrees);
  wait(2, sec);
  // 36, 27
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  IgnoreX(36, 22, 0, 2.3, 60, 35, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  // 11, 4.5
  goTo(2.2, 4, -1, 2.3, 60, 35, 0.5);
  //decrease y
  wait(200,msec);
  Sorter.spin(fwd, 100, pct);
  wait(300, msec);
  Indexer.stop(brake);
  wait(700, msec);
  Sorter.stop(hold);
  Indexer.spin(fwd, 100, pct);

  //2nd
  backLinear(-15, -35, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(27, 55.5, 1, 1.8, 60, 35, 0.5);
 //increase y
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.stop(brake);
  IgnoreY(16, 62.5, -1, 2.1, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  //increase y
  Sorter.spin(fwd, 13, volt);
  wait(300, msec);
  Indexer.stop(brake);
  wait(400, msec);
  Sorter.stop(hold);
  Indexer.spin(fwd, 100, pct);

  //3rd
  backLinear(-10, -20, 2);
  
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  IgnoreX(26.5, 98, 1, 2.1, 60, 35, 0.5);
  backLinear(-10, -20, 2);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  IgnoreY(15.75, 140.5, -1, 1.8, 60, 35, 0.5);
  //lower x
  Sorter.spin(fwd, 13, volt);
  wait(300, msec);
  Indexer.stop(brake);
  wait(400, msec);
  Sorter.stop(hold);

  
  //4th
  backLinear(-10, -25, 2);
  //Increase X
  Indexer.spin(fwd, 100, pct);
  IgnoreY(63.5, 102, 1, 1.8, 60, 35, 0.5);
  Indexer.stop(brake);
  RightIntake.stop(brake);
  LeftIntake.stop(brake);
  //Increase X
  Indexer.stop(brake);
  IgnoreX(70.5, 115, -1, 2.1, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 13, volt);
  wait(600, msec);
  Sorter.stop(hold);


  //5th
  backLinear(-6, -20, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct); 
  Indexer.spin(fwd, 100, pct);
  IgnoreY(112.5, 116, 1, 1.9, 60, 35, 0.5);
  Indexer.stop(brake);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);

  goTo(130.5, 118, -1, 2.1, 60, 35, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 13, volt);
  wait(600, msec);
  Sorter.stop(hold);

  /*
  // 6th
  backLinear(-27, -20, 2);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  goTo(120.25, 61, 1, 2.1, 60, 35, 0.5);
  IgnoreY(126, 58.5, 1, 2.1, 60, 35, 0.5);
  */
  /*
  turnRight(176);
  LeftIntake.spin(fwd, -100, pct);
  RightIntake.spin(fwd, -100, pct);
  
  BackLeftDrive.spin(fwd, 45, pct);
  BackRightDrive.spin(fwd, 45, pct);
  FrontRightDrive.spin(forward, 45, pct);
  FrontLeftDrive.spin(fwd, 45, pct);

  wait(500, msec);
  
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
  BackRightDrive.spin(fwd, 30, pct);
  FrontRightDrive.spin(fwd, 30, pct);
  FrontLeftDrive.spin(fwd, 30, pct);

  wait(1000, msec);
  BackLeftDrive.spin(fwd, -30, pct);
  FrontLeftDrive.spin(fwd, -30, pct);

  wait(400, msec);
  
  BackLeftDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  LeftIntake.stop(coast);
  RightIntake.stop(coast);
  wait(100, msec);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  */


  wait(5, sec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);

}

void homeRow(){
  Inertial.setHeading(180, degrees);
  wait(2000, msec);
  Indexer.spin(fwd, 25, pct);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  goTo(18.75, -12, 1, 2.1, 60, 55, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 100, pct);
  wait(200, msec);
  Indexer.stop(brake);
  wait(250, msec);
  Sorter.spin(reverse, 25, pct);
  Indexer.spin(fwd, 100, pct);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(52, -75, -85);
  Indexer.stop(brake);
  IgnoreX(91.75, 8.25, -1, 2.2, 60, 60, 0.5);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  backLinear(-12, -30, 3);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  IgnoreY(145.25, -8, -1, 2, 60, 45, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 100, pct);
  wait(500, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  wait(500, msec);
  backLinear(-6, -40, 4);


  wait(5, sec);
  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
  /*
  goTo(-12.5, -17.5, 1, 2.2, 60, 25, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Sorter.spin(fwd, 100, pct);
  wait(300, msec);
  Sorter.stop(hold);
  wait(200, msec);

  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(63, -80, -92);
  Indexer.stop(brake);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  goTo(26.6, 6, -1, 3.2, 60, 25, 0.5);
  Sorter.spin(fwd, 100, pct);
  wait(450, msec);

  backLinear(-15, -25, 5);
  goTo(60, 7, -1, 3.1, 100, 28, 0.5);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  Indexer.spin(fwd, 100, pct);
  Sorter.spin(fwd, 100, pct);
  goTo(87, 3, 1, 3.2, 100, 28, 0.5);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  wait(700, msec);
  Sorter.stop(hold);
  backLinear(-15, -25, 3);
  Sorter.spin(fwd, 100, pct);
  wait(350, msec);
  Sorter.stop(hold);
  wait(100, msec);
  */
}

void homeRowRight(){
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(23.5, 70, 25);
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
  turnCurve(58, -85, -60);
  
  Indexer.spin(fwd, 13, volt);
  IgnoreX(68, -1.25, 1, 2.2, 60, 45, 0.5);
  
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-14, -40, 3);

  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 80, pct);
  Indexer.spin(fwd, 80, pct);

  IgnoreY(127.5, 26, 1, 1.75, 60, 35, 0.5);

  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);

  backLinear(-12, -40, 3);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
}

void rightAndSide(){

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
  Inertial.setHeading(270, deg);
  wait(2, sec);
  LeftIntake.spin(fwd, 100, pct);
  RightIntake.spin(fwd, 100, pct);
  turnCurve(16, 15, 70);
  LeftIntake.stop(brake);
  RightIntake.stop(brake);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(400, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.spin(reverse, 100, pct);
  RightIntake.spin(reverse, 100, pct);
  turnCurve(51, -50, -85);
  
  IgnoreX(53.5, 1.25, -1, 2.2, 60, 45, 0.5);
  Indexer.spin(fwd, 13, volt);
  Sorter.spin(fwd, 100, pct);
  wait(600, msec);
  Indexer.stop(brake);
  Sorter.stop(hold);
  LeftIntake.stop(hold);
  RightIntake.stop(hold);

  backLinear(-14, -40, 3);

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
  backLinear(-12, -40, 3);

  BackLeftDrive.stop(coast);
  BackRightDrive.stop(coast);
  FrontLeftDrive.stop(coast);
  FrontRightDrive.stop(coast);
  
}

