#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor BackLeftDrive = motor(PORT1, ratio18_1, false);
motor BackRightDrive = motor(PORT4, ratio18_1, true);
motor FrontLeftDrive = motor(PORT11, ratio18_1, false);
motor FrontRightDrive = motor(PORT20, ratio18_1, true);
motor Sorter = motor(PORT8, ratio18_1, true);
motor Indexer = motor(PORT15, ratio18_1, true);
inertial Inertial = inertial(PORT2);
motor LeftIntake = motor(PORT3, ratio18_1, false);
motor RightIntake = motor(PORT13, ratio18_1, true);
rotation LeftRotation = rotation(PORT12, true);
rotation RightRotation = rotation(PORT10, true);
line LineSensor = line(Brain.ThreeWirePort.B);
limit Limit = limit(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}