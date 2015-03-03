#Elementary data structures
Our example of a queue is a circular queue of size QUEUE_MAX which
has (QUEUE_MAX - 1) slots
Important cases in circular queues.
1. Queue overflow.
   if(HEAD == (tail + 1) % QUEUE_SIZE)
   	   "Queue Overflow"
2. Queue underflow.
   if (HEAD == TAIL)
      "Queue Underflow"