#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct  {
  int arr[STACK_SIZE];
  int tos;
} stack;


stack * create_stack ()
{
  stack * s =  malloc(sizeof(stack));
  s->tos = -1;
  return s;
}

int stack_empty(stack * s)
{
  if (s->tos == -1)
    return 1;
  return 0;
}

int pop(stack *s)
{
  if (stack_empty(s)) {
    printf("Stack UnderFlow\n");
    exit(-1);
  }
  s->tos--;
  return s->arr[s->tos+1];
}
/*
 *We are not checking the stack overflow as the CLRS book suggests,
 *we don't worry
 */
void push(stack *s, int data)
{
  s->tos += 1;
  s->arr[s->tos] = data;
}

int main(void)
{
  return 0;
}
