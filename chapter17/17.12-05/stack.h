#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>
#define MAXSIZE 100

typedef char item;

typedef struct
{
    item data[MAXSIZE];
    int top;
} stack;

void init(stack *st);

bool isempty(stack *st);

bool isfull(stack *st);

bool push(stack *st, item val);

bool pop(stack *st, item *val);

#endif
