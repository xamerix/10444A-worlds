#include "main.h"
using namespace pros;
Motor intake(19,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_DEGREES);
Motor unwind(8,E_MOTOR_GEARSET_06,false,E_MOTOR_ENCODER_DEGREES);

/*
Motor LF(10,E_MOTOR_GEARSET_06,true);
Motor LT(2,E_MOTOR_GEARSET_06,false);
Motor LB(21,E_MOTOR_GEARSET_06,true);
Motor RF(9,E_MOTOR_GEARSET_06,false);
Motor RT(5,E_MOTOR_GEARSET_06,true);
Motor RB(3,E_MOTOR_GEARSET_06,false);

Motor_Group LeftMotors({LF,LT,LB});
Motor_Group RightMotors({RF,RT,RB});
*/
Motor_Group pullback({intake, unwind});
ADIDigitalIn slingLimit('B');
ADIDigitalOut slingRelease('C');
ADIDigitalOut endgames('E');
ADIDigitalOut bands('A');
int stateOP;
int unwindTimeOP = 0;
int slingTimeOP = 0;
int shootingCountOP = 0;
bool intakeBool = false;
bool shootingOP;
int motorpos;
bool slingreleaseValue;
int pressed; 
bool unwindComplete;
bool pulling;
int desiredIntakeValue;