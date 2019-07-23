#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef enum {EMPTY, DELETED, INUSE} SlotStatus;

typedef struct
{
  Key key;
  Value value;
  SlotStatus status;
} Slot;

#endif
