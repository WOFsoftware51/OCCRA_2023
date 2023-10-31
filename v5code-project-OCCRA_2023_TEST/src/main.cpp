/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\drive                                            */
/*    Created:      Thu Sep 21 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// Left_Drive           motor29       B               
// Right_Drive          motor29       A               
// Shooter1             motor29       C               
// Shooter2             motor29       D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

  void setShooterSpeed()
  {
    Shooter2.setVelocity(1.0, percent);
  }

int main() {
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
   //float shootVal1 = 0;
   bool shootBool1 = false;  //
   bool shootBool2 = false;
   float leftSpeed = 0;
   float rightSpeed = 0;
 
  while(true)
  {
    
    float xSpeed = Controller1.Axis3.position();
    float rotation = (-Controller1.Axis1.position())*0.5;
    float shootVal1 = Controller2.Axis2.position(); //Shooter
    float shootVal2 = Controller2.Axis3.position(); //Intake




    // if(Controller2.ButtonL1.pressing() == 1)
    // {
    //   Shooter2.setVelocity(1.0, percent);   
    // }
    // else
    // {
    //   Shooter2.setVelocity(0.0, percent);    
    // }

    // if(Controller1.ButtonR1.pressing()==1)
    // {
    //    shootBool2 = true;
    // }
    // else
    // {
    //   shootBool2 = false;
    // }


    // leftSpeed = Controller1.Axis3.position();
    // rightSpeed = Controller1.Axis2.position();
     leftSpeed = xSpeed - rotation;
     rightSpeed = xSpeed + rotation;


    float maxThing = fmax(fabs(leftSpeed), fabs(rightSpeed));
    
    if(maxThing>1)
    {
      leftSpeed /= maxThing;
      rightSpeed /= maxThing;
    }
  
    Right_Drive.setVelocity(rightSpeed, percent);
    Left_Drive.setVelocity(leftSpeed, percent);

    // if(shootBool1){
    //   Shooter1.setVelocity(0.65, percent);
    // }else{
    //   Shooter1.setVelocity(0, percent);
    // }
    // if(shootBool2){
    //    Shooter2.setVelocity(1.0, percent);
    // }
    // else {
    //    Shooter2.setVelocity(0.0, percent);

   // }

    Shooter1.setVelocity((shootVal1)*0.65, percent);
    Shooter2.setVelocity((shootVal2), percent);


    Right_Drive.spin(forward);
    Left_Drive.spin(forward);
    Shooter1.spin(forward);
    Shooter2.spin(forward);

        // printf("%d\n",Controller1.ButtonL1.pressing());
  } 


}


