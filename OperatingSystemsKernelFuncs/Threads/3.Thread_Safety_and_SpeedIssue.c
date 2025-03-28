//  The problem:
// If we run and (time it optionally), we can observe that everytime you run this program we get different result.
// If you observe the code, the threads are racing to increment the counter which is leading to `RACE CONDITION`.
// This is why we need to use locks so that when one thread is updating the value of the counter, another thread has to wait.

//  A possible fix is to make the operation ATOMIC.

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

#define BIG 1000000000UL
uint32_t counter = 0;

void *count_to_big(void *arg) {
  for (uint32_t i = 0; i < BIG; i++) {
    counter++;
  }
  return NULL;
}

int main() {
  pthread_t thread1;
  pthread_create(&thread1, NULL, count_to_big, NULL);
  count_to_big(NULL);
  pthread_join(thread1, NULL);
  printf("Done. Counter = %u\n", counter);
  return 0;
}
