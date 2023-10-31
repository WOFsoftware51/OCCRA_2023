#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor29 Left_Drive = motor29(Brain.ThreeWirePort.B, false);
motor29 Right_Drive = motor29(Brain.ThreeWirePort.A, true);
motor29 Shooter1 = motor29(Brain.ThreeWirePort.C, false);
motor29 Shooter2 = motor29(Brain.ThreeWirePort.D, false);

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