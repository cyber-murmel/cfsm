# CFSM
A lightweight state machine library in C

## How to use
Example `parity.c`:
```C
// 1. Define the type of your event
typedef unsigned int event_t;
// 2. Include library
#include "fsm.h"
// 3. Instantiate your states
STATE(EVEN);
STATE(ODD);
// 4. Define behaviour of states
state_t transition_EVEN(event_t event) {
  if (1 == event)
    return ODD;
  else
    return EVEN;
}
state_t transition_ODD(event_t event) {
  if (1 == event)
    return EVEN;
  else
    return ODD;
}
// 5. Run FSM in main loop
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
  if(1 < argc) {
    int number = atoi(argv[1]);
    state_t state = EVEN;
    while (0 != number) {
      // perform transition
      state = state.transition(number & 1);
      // "get new event"
      number >>= 1;
    }
    printf("%s\n", state.text);
  }
  return 0;
}
```

```bash
$ git clone https://github.com/cyber-murmel/cfsm.git
$ vim parity.c
$ gcc -I cfsm/inc parity.c -o parity && ./parity 42
ODD
```