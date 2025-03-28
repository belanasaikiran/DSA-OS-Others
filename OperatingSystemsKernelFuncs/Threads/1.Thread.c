// Create/Join threads

// Using pthread API here.
//
// Create - `pthread_create(pthread_t *thread, const pthread_attr_t *attr)`
// Cancel - `pthread_cancel(pthread_t thread)
//

// Below is a very very basic thread
#include <pthread.h>
#include <stdio.h>
#include <ulimit.h>
#include <unistd.h>

void *myTurn(void *arg) {
  for (int i = 0; i < 5; i++) {
    sleep(1);
    printf("My Turn! - %d \n", i);
  }
  return NULL;
}

void yourTurn() {
  for (int i = 0; i < 3; i++) {
    sleep(1);
    printf("Your Turn! - %d\n", i);
  }
}

int main() {
  pthread_t newthread;

  pthread_create(&newthread, NULL, myTurn, NULL);
  // myTurn();
  yourTurn();
  pthread_join(newthread, NULL);


  return 0;
}
