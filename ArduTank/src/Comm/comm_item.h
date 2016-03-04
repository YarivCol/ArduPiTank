#ifndef ARADUTANK_COMM_COMMITEM_H_INCLUDED
#define ARADUTANK_COMM_COMMITEM_H_INCLUDED

#include <inttypes.h>

class CommItemInterface
{
  public:
    virtual int8_t send (uint8_t * buffer, uint8_t buffer_size) = 0;
    virtual bool   recv (uint8_t * buffer, uint8_t* buffer_size) = 0;
    virtual void   connect () = 0;
};


#endif
