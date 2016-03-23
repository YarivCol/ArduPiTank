#include "general_command_callbacks.h"

#define MAJOR_VERSION 1
#define MINOR_VERSION 0

GetVersionResponse GeneralCommandCallbacks::get_version(){
  GetVersionResponse response = {MAJOR_VERSION, MINOR_VERSION};
  return response;
}
