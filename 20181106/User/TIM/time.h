#ifndef TIME_H
#define TIME_H
#include "pbdata.h"

typedef struct
{
	unsigned char UpdateITFlag;
	unsigned short ITCounts;
  unsigned short onesecond;
}timer_t;

extern timer_t Timer2_T;
extern timer_t Timer3_T;

void TIME2_Init(u16 prd,u16 psc);
void TIME3_Init(u16 prd,u16 psc);

#endif
