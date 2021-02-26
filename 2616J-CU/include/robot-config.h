using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor BackLeftDrive;
extern motor BackRightDrive;
extern motor FrontLeftDrive;
extern motor FrontRightDrive;
extern motor Sorter;
extern motor Indexer;
extern inertial Inertial;
extern motor LeftIntake;
extern motor RightIntake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );