
#pragma once

#include "defines.h"

i16 ABS16(i16 i)
{
    i16 res;
    if 	(INT16_MIN == i) {res = INT16_MAX;}
    else{res = i < 0 ? -i : i;}
    return res;
}


// Valeur absolue sans le signe.
#define ABS(_x) ((_x) < 0 ? -(_x) : (_x))

// Maximum de deux valeurs.
#define MAX(a,b)((a)>(b)?(a):(b))

// Minimum de deux valeurs.
#define MIN(a,b)((a)<(b)?(a):(b))
// Fixe une valeur entre une limite minimale définie et une limite maximale.
#define CLAMP(min,val,max)((val)>(max)?(max):((val)<(min)?(min):(val)))
// Arrondit une valeur à virgule flottante à la valeur entière la plus proche.
#define ROUND(t,x)((x)>=0?(t)((x)+0.5):(t)((x)-0.5))
// Echange deux valeur.
#define SWAP(t,x,y) {t tmp = x; x = y; y = tmp;}
