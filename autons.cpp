#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
const int INTAKE_SPEED = 51;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.


void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
void slingshotControlA(void * param) {
  while (true) {
  if (stateOP == 0) {
        if (!slingLimit.get_value() && pressed == 1) {
          intakeBool = true;
          pullback.move(-127);
        }
        if (slingLimit.get_value() && pressed == 1) {
          pressed = 0;
         if (pressed == 0){
          intakeBool = true;
          slingRelease.set_value(false);
          delay(500);
          pullback.move_relative(800,600);
          pressed = 2;
          unwindComplete = true;
          pulling = false;
         }
         if (intakeBool) {
          intake = 127;
         }
         else {
          intake = desiredIntakeValue;
         }
        }
        }    
      if (stateOP == 1) {
        slingRelease.set_value(true);
        pulling = true;
        delay(850);
        pressed = 1;
        intakeBool = false;
        stateOP = 0;
        }
        
      pros::delay(30);
  }
  }
void shoot() {
  stateOP = 1;
  pressed = 1;
}
void SoloWP() {

}
void rightSide() {
  Task sling(slingshotControlA);
  intake = 127;
  chassis.set_drive_pid(45,DRIVE_SPEED,false,true);
  chassis.wait_drive();
  chassis.set_turn_pid(26,TURN_SPEED);
  chassis.wait_drive();
  delay(400);
  shoot();
  delay(1000);
  /*
  chassis.set_turn_pid(45,TURN_SPEED);
  delay(1500);
  chassis.wait_drive();
  chassis.set_drive_pid(28,DRIVE_SPEED,false,true);
  delay(1500);
  chassis.wait_drive();
  */
 chassis.set_turn_pid(-45,TURN_SPEED);
 chassis.set_drive_pid(-49,DRIVE_SPEED,true,true);
 chassis.wait_drive();
 /* delay(450);
  chassis.set_drive_pid(-25,DRIVE_SPEED,false,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-45,TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(74,INTAKE_SPEED,true,true);
  chassis.wait_drive();
  chassis.set_turn_pid(45,TURN_SPEED);
  chassis.wait_drive();
  delay(100);
  shoot();
  delay(400);
  chassis.set_turn_pid(-45,TURN_SPEED);
  chassis.set_drive_pid(-110,DRIVE_SPEED,true,true);
  chassis.wait_drive();
  chassis.set_turn_pid(0,TURN_SPEED);
  chassis.set_drive_pid(-28,DRIVE_SPEED,false,true);
  intake.move_relative(100,600);*/
  delay(400);
  bands.set_value(true);
  delay(500);
  bands.set_value(false);


}
void leftSide() {

}
void Skills() {

}
