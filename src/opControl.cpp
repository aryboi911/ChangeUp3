#include "vex.h"
#include "opControl.h"

using namespace vex;

int flywheelToggle;

void joystickControl(){
  FrontRightDrive.spin(fwd, Controller1.Axis2.position(), pct);
  FrontLeftDrive.spin(fwd, Controller1.Axis3.position(), pct);
  BackRightDrive.spin(fwd, Controller1.Axis2.position(), pct);
  BackLeftDrive.spin(fwd, Controller1.Axis3.position(), pct);
  
}

void intakeControl(){
  //Intake
  if(Controller1.ButtonR1.pressing()){
    LeftIntake.spin(fwd, 100, pct);
    RightIntake.spin(fwd, 100, pct);
  }

  else if(Controller1.ButtonRight.pressing()){
    LeftIntake.spin(reverse, 100, pct);
    RightIntake.spin(reverse, 100, pct);
  }

  else{
    LeftIntake.stop(brake);
    RightIntake.stop(brake);
  }
}

void indexerControl(){
  //Convey Balls
  if (Controller1.ButtonL1.pressing()){
    Indexer.spin(fwd, 100, pct);
  }

  else{
    Indexer.stop(brake);
  }
}

void sorterControl(){
  //Outtake
  if(Controller1.ButtonR2.pressing()){
    LeftIntake.spin(reverse, 100, pct);
    RightIntake.spin(reverse, 100, pct);
    Indexer.spin(reverse, 100, pct);
    Sorter.stop(hold);
  }

  //Middle Goal Dump
  if(Controller1.ButtonL2.pressing()){
    Sorter.spin(fwd, 13, volt);
    wait(100, msec);
    while(Controller1. ButtonL2.pressing()){
      Sorter.spin(fwd, 13, volt);
      Indexer.spin(fwd, 100, pct);
      intakeControl();
      joystickControl();
    }
    // BackLeftDrive.spin(fwd, 15, pct);
    // BackRightDrive.spin(fwd, 15, pct);
    // FrontLeftDrive.spin(fwd, 15, pct);
    // FrontRightDrive.spin(fwd, 15, pct);
    
  }
  //Poop
  else if(Controller1.ButtonY.pressing()){
    Sorter.spin(fwd,-100, pct);
    if(Controller1.ButtonL1.pressing() == false){
      Indexer.stop(brake);
    }
  }

  else{
    Sorter.stop(hold);
  }
}

void screenControl(){
  if(Controller1.ButtonX.pressing()){
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("I: ");
    Controller1.Screen.print(Indexer.temperature(celsius));
    Controller1.Screen.print("   BL: ");
    Controller1.Screen.print(BackLeftDrive.temperature(celsius));
    Controller1.Screen.newLine();
    Controller1.Screen.print("S: ");
    Controller1.Screen.print(Sorter.temperature(celsius));
    Controller1.Screen.print("  BR: ");
    Controller1.Screen.print(BackRightDrive.temperature(celsius));
    Controller1.Screen.newLine();
    Controller1.Screen.print("B: ");
    Controller1.Screen.print(Brain.Battery.capacity(pct));
    Controller1.Screen.print("      RI: ");
    Controller1.Screen.print(RightIntake.temperature(celsius));
  }
}