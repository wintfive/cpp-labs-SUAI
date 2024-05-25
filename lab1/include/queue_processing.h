#ifndef QUEUE_PROCESSING
#define QUEUE_PROCESSING
#include "queue1.h"

Queue1* CreateQueue();
Queue1* PushQueue(Queue1* queue);
Queue1* PopQueue(Queue1* queue);
void    PrintQueue(Queue1* queue);
void    FindSpread(Queue1* queue);
Queue1* CopyQueue(Queue1* queue);
Queue1* MergeQueues(Queue1* first, Queue1* second);
void    DeleteQueue(Queue1* queue);

#endif /* QUEUE_PROCESSING */