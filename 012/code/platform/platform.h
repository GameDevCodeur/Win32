
#pragma once

#include "../defines.h"

GDC_FUNC(b8, platform_system_startup, 
        (const char * application_name,	i16 x, i16 y, i16 width, i16 height));
					
GDC_FUNC(b8, platform_pump_messages,(void));
GDC_FUNC(void, platform_system_shutdown,(void));
