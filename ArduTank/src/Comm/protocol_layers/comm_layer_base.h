#ifndef ARADUTANK_COMM_PROTOCOLLAYERS_COMMLAYERBASE_H_INCLUDED
#define ARADUTANK_COMM_PROTOCOLLAYERS_COMMLAYERBASE_H_INCLUDED

#include "../comm_item.h"

class CommLayerBase: public CommItemInterface
{
  public:
    int8_t send (uint8_t * buffer, uint8_t buffer_size);
    bool   recv (uint8_t * buffer, uint8_t* buffer_size);
    void   connect ();
    CommItemInterface * underlaying_comm;
};


#endif
