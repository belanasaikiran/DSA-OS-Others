//  A possible/easiest fix is to make the operation ATOMIC.
// But it makes the code much fragile if we switch the OS.
// So, we can use MUTEX LOCKS (MUTUAL EXCLUSION). It tells that a thread is
// already working on a func, others have to wait.
//
//
// NOTE: Only one thread can have the lock at a time.
//
//
// RUN this program and see the time it takes.
// ** Does it look like it is taking forever. I think the guy on YT said, it takes 14 min lol where it took 4 seconds before without implementation of lock but it did lead to wrong results

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // 1. create a lock

void *count_to_big(void *arg) {
  for (uint32_t i = 0; i < BIG; i++) {
    pthread_mutex_lock(
        &lock); // 2. any thread has to wait here until it can get the lock.
    counter++;
    pthread_mutex_unlock(
        &lock); // 3. after thread's operation, it will release the lock
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
