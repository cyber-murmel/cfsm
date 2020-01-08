#include <stdio.h>
#include <stdlib.h>
#include "example.h"

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
