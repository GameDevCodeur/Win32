
#pragma once

#include "defines.h"

// Valeur absolue sans le signe.
#define ABS(x)(((x)<0)?(-x):(x))
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
