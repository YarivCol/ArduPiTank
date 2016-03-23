#include <Adafruit_MotorShield.h>
#include "motor_command_callbacks.h"
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

MotorCommandCallbacks::MotorCommandCallbacks()
{
  speed = 40;
  is_moving = false;
  direction = DirectionEnum_FORWARD;
}


void MotorCommandCallbacks::init(){
  AFMS.begin();

  leftMotor->setSpeed(speed);
  rightMotor->setSpeed(speed);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  // turn on motor
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

void MotorCommandCallbacks::move_tank(MoveCommand move_command){
  if (move_command.direction == DirectionEnum_FORWARD) {
    leftMotor->run(FORWARD);
    rightMotor->run(FORWARD);
  }
  else
  {
    leftMotor->run(BACKWARD);
    rightMotor->run(BACKWARD);
  }
  is_moving = true;
  direction = move_command.direction;
}

void MotorCommandCallbacks::stop_tank(){
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  is_moving = false;
}

GetStatusResponse MotorCommandCallbacks::get_status(){
  GetStatusResponse response = {direction, speed, is_moving};
  return response;
}
