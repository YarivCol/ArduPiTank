#ifndef _ARDUTANK_MESSAGES_COMMANDHANDLER_COMMANDHANDLER_H_
#define _ARDUTANK_MESSAGES_COMMANDHANDLER_COMMANDHANDLER_H_

#include <pb_decode.h>
#include <inttypes.h>
#include "../command_decoder/command_decoder.h"
#include "../response_encoder/response_encoder.h"
#include "motor_command_callbacks/motor_command_callbacks.h"
#include "general_command_callbacks/general_command_callbacks.h"

class CommandHandler {
  public:
    void init();
    void handle(uint8_t * buffer, size_t size_of_buffer);
  private:
    CommandDecoder decoder;
    ResponseEncoder encoder;
    MotorCommandCallbacks motor_command_callbacks;
    GeneralCommandCallbacks general_command_callbacks;
    void send_response(void * response, const pb_field_t response_type[]);
};

#endif
