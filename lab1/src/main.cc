#include "../include/menu.h"
#include "../include/queue_processing.h"

int main() {
  Queue* queue = CreateQueue();
  MenuRealization(queue);
  return 0;
}