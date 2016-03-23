#ifndef _ARDUTANK_MESSAGES_COMMANDDECODER_COMMANDDECODER_H_
#define _ARDUTANK_MESSAGES_COMMANDDECODER_COMMANDDECODER_H_

#include <pb_decode.h>

class CommandDecoder {
  public:
    const pb_field_t* decode_command_type(pb_istream_t *stream);

    bool decode_command_contents(pb_istream_t *stream, 
                                 const pb_field_t fields[],
                                 void *dest_struct);
};

#endif
