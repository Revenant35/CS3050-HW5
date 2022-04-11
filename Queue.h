
#ifndef HW5_QUEUE_H
#define HW5_QUEUE_H

#include <stdbool.h>


typedef struct queue_struct *Queue;

Queue Create_Queue();
void* deQueue(Queue Q);
void enQueue(Queue Q, void* vertex);
bool isEmpty(Queue Q);


#endif //HW5_QUEUE_H
