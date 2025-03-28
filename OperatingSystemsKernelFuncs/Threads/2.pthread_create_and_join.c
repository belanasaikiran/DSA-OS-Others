// Below is a very very basic thread
#include <pthread.h>
#include <stdio.h>
#include <ulimit.h>
#include <unistd.h>


// 1. We need pointers to identify threads. Even if void returns null, we can use the pointer to differentiate the thread execution in running
void *myTurn(void *arg) {
int* iptr = (int*)  arg;
  for (int i = 0; i < 5; i++) {
    sleep(1);
    printf("My Turn! - %d - %d\n", i, *iptr);
    (*iptr)++;
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
  int v = 5;

  pthread_create(&newthread, NULL, myTurn, &v); // 2. adding the pointer here which goes to void & arg in myturn func
  // myTurn();
  yourTurn();
  pthread_join(newthread, NULL);
  printf("thread's done: v=%d\n", v); // 3. check the value;


  return 0;
}
