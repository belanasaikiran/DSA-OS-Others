// SPEED ISSUE: https://www.youtube.com/watch?v=9axu8CUvOKY
// Firstly, terminology!
// ************* CONCURRENCY & PARALLELISM ******************
//
// PARALLELISM:
// If two processes or threads are working in parallel, they should work at the
// same. parallelism needs hardware support (multiple cores).
//
// CONCURRENCY:
// Imagine a machine has only 1 core, it can run 1 thread at a time. What it
// will do is. It will run one code for short amount of time and switch to
// another one. This is also called `CONTEXT SWITCHING` but it running by
// switching b/w the processes we don't even notice it.
//
// MEMORY SHARING:
// A lot things can prevent you from getting parallsm in threads. One of them is
// MEMROY SHARING. We have a variable shared b/w two threads The problem the
// threads are accessing the variable from memory a billion times. It keeps
// shuggling back and forth and the OS might just stick bothe of these to same
// cofre to avoid memory sharing contention. This is going to affect it.
//
// NOW, we added locks which also added more delay leading to Minutes of run
// time instead of seconds.
//
// Each thread has to wait for the other one to release the lock and it moves
// forward to take turns which has a lot of overhead.
//

//  THEN why would be want to use thread.
//  We can do something with this situation.
//  We can use threads to run different functions that doesn't affect the others.
//
// Keep the memory sharing limited.
//
// NOTE: Threads are also useful for building Interfaces to make them be responsive.


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
