#include "example.h"

state_t transition_ODD(event_t event) {
  if (1 == event)
    return EVEN;
  else
    return ODD;
}