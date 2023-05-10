
#pragma once

#include "defines.h"

b8 platform_system_startup(	const char * application_name,
							u32 x, u32 y, u32 width, u32 height);
					
b8 platform_pump_messages(void);

void platform_system_shutdown(void);
