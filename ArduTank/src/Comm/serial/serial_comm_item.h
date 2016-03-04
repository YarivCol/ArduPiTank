#ifndef ARADUTANK_COMM_SERIAL_COMMITEM_H_INCLUDED
#define ARADUTANK_COMM_SERIAL_COMMITEM_H_INCLUDED

#include "../comm_item.h"

class SerialCommItem : public CommItemInterface
{
public:
  int8_t send (uint8_t * buffer, uint8_t buffer_size);
  bool   recv (uint8_t * buffer, uint8_t* buffer_size);
  int8_t available_bytes();
  void   connect ();
};


#endif
