#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_SIZE 10

typedef struct {
  int arr[QUEUE_SIZE];
  int head;
  int tail;
} queue;

int queue_empty(queue *q)
/*
 * A queue is empty when the head and tail are equal
 */
{
  if (q->head == q->tail)
    return 1;
  return 0;
}

queue * create_queue()
{
  /*
   *Initially when the queue is empty the head and tail are both 0
   */
  queue *q = malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
  return q;
  
}

void enqueue(queue * q, int data)
{
  q->arr[q->tail] = data;
  if (q->tail == QUEUE_SIZE - 1)
    q->tail = 0;
  else
    q->tail += 1; 
}

int dequeue(queue *q)
{
  int data = q->arr[q->head];
  if (q->head == QUEUE_SIZE - 1)
    q->head = 0;
  else q->head += 1;
  return data;
}

int main()
{
  queue *q = create_queue();
  enqueue(q, 10);
  assert(dequeue(q) == 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  assert(dequeue(q) == 20);
  assert(dequeue(q) == 30);
  assert(dequeue(q) == 40);
  assert(dequeue(q) == 50);
  return 0;
}
