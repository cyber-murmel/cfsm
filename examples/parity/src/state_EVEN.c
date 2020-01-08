#include "example.h"

state_t transition_EVEN(event_t event) {
  if (1 == event)
    return ODD;
  else
    return EVEN;
}