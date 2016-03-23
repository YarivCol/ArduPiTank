#ifndef _ARDUTANK_MESSAGES_COMMANDHANDLER_MOTORCOMMANDCALLBACKS_H_
#define _ARDUTANK_MESSAGES_COMMANDHANDLER_MOTORCOMMANDCALLBACKS_H_

#include "../../../protos/output/ArduTank.pb.h"

class MotorCommandCallbacks {
  public:
    MotorCommandCallbacks();

    void init();

    void move_tank(MoveCommand move_command);

    void stop_tank();

    GetStatusResponse get_status();
  private:
    uint8_t speed;
    bool is_moving;
    DirectionEnum direction;
};

#endif
