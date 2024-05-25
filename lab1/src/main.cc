#include "../include/menu.h"
#include "../include/queue_processing.h"

int main() {
  Queue1* queue = CreateQueue();
  MenuRealization(queue);
  return 0;
}