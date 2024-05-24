#ifndef QUEUE_PROCESSING
#define QUEUE_PROCESSING
#include "queue.h"

Queue* CreateQueue();
Queue* PushQueue(Queue* queue);
void   PrintQueue(Queue* queue);
void   DeleteQueue(Queue* queue);

#endif /* QUEUE_PROCESSING */