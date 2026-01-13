#ifndef ZONE_H
#define ZONE_H
#include <stddef.h>
#include <stdint.h>

typedef struct
{
	double x, y, w, h;
} Zone;

extern Zone*  g_mapZone[21];
extern size_t g_mapZoneSize[21];

#endif