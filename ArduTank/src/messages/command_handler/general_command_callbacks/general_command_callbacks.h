#ifndef _ARDUTANK_MESSAGES_COMMANDHANDLER_GENERALCOMMANDCALLBACKS_H_
#define _ARDUTANK_MESSAGES_COMMANDHANDLER_GENERALCOMMANDCALLBACKS_H_

#include "../../../protos/output/ArduTank.pb.h"

class GeneralCommandCallbacks {
  public:
    GetVersionResponse get_version();

};

#endif
