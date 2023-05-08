//
// GAMEDEVCODEUR
// Fenetre win32 api
//

#include "platform.h"

int main(void) 
{
  if(!platform_system_startup("Apprendre a programmer Windows", 500, 200, 1080, 720))
  {
	  return -1;						
  }
  
  if(!platform_pump_messages())
  {
	  return -2;
  }
  
  platform_system_shutdown();
	
}
