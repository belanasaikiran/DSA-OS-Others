// Below is a very very basic thread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ulimit.h>
#include <unistd.h>

void *myTurn(void *arg) {
  int *iptr = (int *)malloc(sizeof(int)); // 2. create memory on heap using malloc
  // 3. set the var number here
  *iptr = 5;
  for (int i = 0; i < 5; i++) {
    sleep(1);
    printf("My Turn! - %d - %d\n", i, *iptr);
    (*iptr)++;
  }
  return iptr; // return the value the thread returns
}

void yourTurn() {
  for (int i = 0; i < 3; i++) {
    sleep(1);
    printf("Your Turn! - %d\n", i);
  }
}

int main() {
  pthread_t newthread;
  // 4. get the result in this variable my creating a pointer to point to whatever the thread returns.
  int *result;

  // 1. what if we want to allocate main memory instead of creating the varibale
  // in main. We can allocate memory in func myTurn using `malloc`.
  pthread_create(&newthread, NULL, myTurn, NULL);
  // myTurn();
  yourTurn();
  pthread_join(newthread, (void*) &result);
  printf("thread's done: v=%d\n", *result);

  return 0;
}
