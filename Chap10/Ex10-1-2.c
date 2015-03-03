/*
 *Implementing two stacks with one array and neither overflows
 *unless total number of elements in both stacks = n
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 10

typedef struct  {
  int arr[STACK_SIZE];
  int tos_a;
  int tos_b;
} two_stack;

two_stack * create_stack()
{
  two_stack *s = malloc(sizeof(two_stack));
  s->tos_a = -1;
  s->tos_b = STACK_SIZE;
  return s;
}

int stack_a_empty(two_stack *s)
{
  if (s->tos_a == -1)
    return 1;
  return 0;
}

int stack_b_empty(two_stack *s)
{
  if (s->tos_b == STACK_SIZE)
    return 1;
  return 0;
}

void push_a(two_stack * s, int data)
{
  s->tos_a += 1;
  s->arr[s->tos_a] = data;
}

void push_b(two_stack *s, int data)
{
  s->tos_b -= 1;
  s->arr[s->tos_b] = data;
}

int pop_a(two_stack *s)
{
  int data = s->arr[s->tos_a];
  s->tos_a -= 1;
  return data;
}

int pop_b(two_stack *s)
{
  int data = s->arr[s->tos_b];
  s->tos_b += 1;
  return data;
}

int main()
{
  two_stack * stack = create_stack();
  push_a(stack,1);
  assert(pop_a(stack) == 1);
  push_a(stack,2);
  push_a(stack,3);
  push_a(stack,4);
  assert(pop_a(stack) == 4);
  push_b(stack, 10);
  assert(pop_b(stack) == 10);
  
  return 0;
}
