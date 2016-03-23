#include <Arduino.h>
#include "command_handler.h"
#include "../../protos/output/ArduTank.pb.h"

#define SIZE_OF_BUFFER 64

void CommandHandler::init()
{
    motor_command_callbacks.init();
}

void CommandHandler::send_response(void * response, const pb_field_t response_type[])
{
  uint8_t buffer[SIZE_OF_BUFFER];

  pb_ostream_t stream = pb_ostream_from_buffer(buffer + 1,
                                               SIZE_OF_BUFFER -1);

  encoder.encode_response(&stream, response_type, response);

  buffer[0] = stream.bytes_written;

  Serial.write(buffer, stream.bytes_written + 1);
}

void CommandHandler::handle(uint8_t * buffer, size_t size_of_buffer)
{
  pb_istream_t stream = pb_istream_from_buffer(buffer, size_of_buffer);

  const pb_field_t *type = decoder.decode_command_type(&stream);


  if (type == GetVersionCommand_fields)
  {
    GetVersionResponse response = general_command_callbacks.get_version();
    send_response(&response, GetVersionResponse_fields);
  }

  else if (type == MoveCommand_fields)
  {
    MoveCommand msg = {};
    decoder.decode_command_contents(&stream, MoveCommand_fields, &msg);
    motor_command_callbacks.move_tank(msg);
  }
  else if (type == StopCommand_fields)
  {
    motor_command_callbacks.stop_tank();
  }

  else if (type == GetStatusCommand_fields)
  {
    GetStatusResponse response =  motor_command_callbacks.get_status();
    send_response(&response, GetStatusResponse_fields);
  }



}
