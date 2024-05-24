#ifndef QUEUE_PROCESSING
#define QUEUE_PROCESSING
#include "queue.h"

Queue* CreateQueue();
Queue* PushQueue(Queue* queue);
Queue* PopQueue(Queue* queue);
void   PrintQueue(Queue* queue);
void   FindSpread(Queue* queue);
Queue* CopyQueue(Queue* queue);
Queue* MergeQueues(Queue* first, Queue* second);
void   DeleteQueue(Queue* queue);

#endif /* QUEUE_PROCESSING */