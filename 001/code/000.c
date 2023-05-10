//
// GAMEDEVCODEUR
// Fenetre win32 api
//

#include "platform.h"

#define width 800
#define height 600

int main(void) 
{
  
  if(!platform_system_startup("Apprendre a programmer Windows", 500, 200, width, height))
  {
	  return -1;
  }
  
  if(!platform_pump_messages())
  {
	  return -2;
  }
   
  platform_system_shutdown();
  
  return 0;
	
}
