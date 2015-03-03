#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Queue size n means there can be n-1 slots,
//we are keeping the last slot empty
#define QUEUE_SIZE 3

typedef struct {
  int arr[QUEUE_SIZE];
  int head;
  int tail;
} queue;

/*
 * A queue is empty when the head and tail are equal
 */
int queue_empty(queue *q)
{
  if (q->head == q->tail)
    return 1;
  return 0;
}

/*
 *Initially when the queue is empty the head and tail are both 0
 */
queue * create_queue()
{
  queue *q = malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
  return q;
}
/*
 * this formula is important
 * head == (tail + head) % QUEUE_SIZE
 * This tells whether the queue is full or not
 */ 
void enqueue(queue * q, int data)
{
  if (q->head == (q->tail + 1)%QUEUE_SIZE) {
    printf("Stack Overflow\n");
    exit(0);
  } 
  q->arr[q->tail] = data;
  if (q->tail == QUEUE_SIZE - 1)
    q->tail = 0;
  else
    q->tail += 1; 
}

int dequeue(queue *q)
{
  if (q->head == q->tail) {
    printf("stack underflow\n");
    exit(1);
  }
  int data = q->arr[q->head];
  if (q->head == QUEUE_SIZE - 1)
    q->head = 0;
  else q->head += 1;
  return data;
}

int main()
{
  queue *q = create_queue();
  enqueue(q, 5);
  enqueue(q, 6);
  assert(dequeue(q) == 5);
  enqueue(q, 7);
  assert(dequeue(q) == 6);
  enqueue(q, 8);
  assert(dequeue(q) == 7);
  enqueue(q, 7);
  assert(dequeue(q) == 8);
  assert(dequeue(q) == 7);
  return 0;
}
