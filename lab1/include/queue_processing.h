#ifndef QUEUE_PROCESSING
#define QUEUE_PROCESSING
#include "queue.h"
#include "queue1.h"

Queue* CreateQueue();
Queue* PushQueue(Queue* queue);
Queue* PopQueue(Queue* queue);
void   PrintQueue(Queue* queue);
void   FindSpread(Queue1* queue);
Queue* CopyQueue(Queue* queue);
Queue* MergeQueues(Queue* first, Queue* second);
void   DeleteQueue(Queue* queue);

#endif /* QUEUE_PROCESSING */