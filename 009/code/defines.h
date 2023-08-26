
#pragma once

#include "gdcConfig.h"

#include <inttypes.h>
#include "asserts.h"

// Types insigned
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
// Types signed.
typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
// Types float.
typedef float  f32;
typedef double f64;
// Types booleens.
typedef uint8_t b8;
typedef int  b32;

#define TRUE 1
#define FALSE 0

#define Align16(val) ((val + 15) & ~15)

#ifdef __clang__
    #define typeof(x) __typeof__(x)
#else
    // Might even check for __GNUC__?
    #define typeof(x) __typeof(x)
#endif

// Verifier que tous les types sont de la bonne taille.
STATIC_ASSERT(sizeof(u8)  == 1, " b8 attendu doit être de 1 octet.");
STATIC_ASSERT(sizeof(u16) == 2, "u16 attendu doit être de 2 octets.");
STATIC_ASSERT(sizeof(u32) == 4, "u32 attendu doit être de 4 octets.");
STATIC_ASSERT(sizeof(u64) == 8, "u64 attendu doit être de 8 octets.");

STATIC_ASSERT(sizeof(i8)  == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)	
	#define GDC_PLATFORM_WINDOWS 1	
	
	#ifndef _WIN64	
		#error "64-bit is required on Windows!"		
	#endif
	
	void __stdcall Sleep(unsigned long msTimeout); // Required for: WaitTime()
#endif

