
#include "comm_layer_base.h"

int8_t CommLayerBase::send (uint8_t * buffer, uint8_t buffer_size)
{
  return underlaying_comm->send(buffer,buffer_size);
}

bool  CommLayerBase::recv (uint8_t * buffer, uint8_t* buffer_size)
{
  return underlaying_comm->recv(buffer,buffer_size);
}

void CommLayerBase::connect ()
{
  underlaying_comm->connect();
}
