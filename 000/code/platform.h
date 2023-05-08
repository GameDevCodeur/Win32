
#pragma once

#include "defines.h"

b8 platform_system_startup(	const char * application_name,
							i32 x, i32 y, i32 width, i32 height);
					
b8 platform_pump_messages(void);

void platform_system_shutdown(void);

