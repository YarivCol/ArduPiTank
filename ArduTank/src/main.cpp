#include <Wire.h>
#include <Arduino.h>
#include "messages/command_handler/command_handler.h"

CommandHandler command_handler = CommandHandler();

void setup() {

  Serial.begin(115200);
  command_handler.init();
}

void loop() {
//Serial.readBytes(3, size_t length)
 //bb.send(test, 2);
 /*
  delay(1000);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);

  delay(10000);

  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
*/
}

void serialEvent(){
  uint8_t  buffer [64];

  uint8_t size_of_buffer;
  //reads the length of the incoming message
  Serial.readBytes(&size_of_buffer, 1);

  //reads the message, drops the message if faild with timeout
  if (Serial.readBytes(buffer, size_of_buffer) != size_of_buffer) {
    return ;
  }
  
  command_handler.handle(buffer, size_of_buffer);
}
