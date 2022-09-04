#include <stdio.h>

enum {
    STATE_NORMAL,
    STATE_POISON,
    STATE_NUMBLY,
    STATE_CURSE,
};

void setState(int *state, int x);
void currentState(int state);

int main(void)
{
    int input, state = 0, x = 0;

    while (x < 10) {
        printf("Input Number:");
        scanf("%d",&input);
        x+=input;
        setState(&state, x);
        currentState(state);
    }

    return 0;
}

void setState(int *state, int x)
{
    if (x == 3) {
        *state = STATE_POISON;
    } else if (x == 2) {
        *state = STATE_CURSE;
    } else if (x == 1) {
        *state = STATE_NUMBLY;
    } else {
        *state = STATE_NORMAL;
    }
    return;
}

void currentState(int state)
{
    if (state == STATE_POISON) {
        printf("Current State is Poison\n");
    } else if (state == STATE_CURSE) {
        printf("Current State is Curse\n");
    } else if (state == STATE_NUMBLY) {
        printf("Current State is Numbly\n");
    } else {
        printf("Current State is Normal\n");
    }
    return;
}