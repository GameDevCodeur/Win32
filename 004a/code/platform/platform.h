
#pragma once

#include "../defines.h"

b8 platform_system_startup(	const char * application_name,
							u16 x, u16 y, u16 width, u16 height);
					
b8 platform_pump_messages(void);

void platform_system_shutdown(void);
