#ifndef _ARDUTANK_MESSAGES_RESPONSEENCODER_RESPNSEENCODER_H_
#define _ARDUTANK_MESSAGES_RESPONSEENCODER_RESPNSEENCODER_H_

#include <pb_encode.h>

class ResponseEncoder {
  public:
    bool encode_response(pb_ostream_t *stream,
                         const pb_field_t messagetype[],
                         const void *message);
};

#endif
