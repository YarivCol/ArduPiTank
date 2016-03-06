
#include "serial_comm_item.h"
#include <Arduino.h>

#define BAUD_RATE (115200)

int8_t SerialCommItem::send (uint8_t * buffer, uint8_t buffer_size)
{
  return Serial.write(buffer, buffer_size);
}

bool  SerialCommItem::recv (uint8_t * buffer, uint8_t* buffer_size)
{
  int8_t available_bytes_read = Serial.available();
  if (available_bytes_read > 0) {
    *buffer_size = available_bytes_read;
    Serial.readBytes(buffer, *buffer_size);
    return true;
  }
  return false;
}

int8_t SerialCommItem::available_bytes()
{
  return Serial.available();
}

void SerialCommItem::connect ()
{
  Serial.begin(BAUD_RATE);
}
