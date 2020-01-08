#ifndef FSM_H
#define FSM_H

#define STATE(NAME) \
  state_t transition_ ## NAME(event_t event); \
  static state_t NAME = {.transition = transition_ ## NAME, .text = #NAME}

typedef struct state_s {
    struct state_s (*transition)(event_t event);
    char *text;
} state_t;

#endif // FSM_H
