#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#define NUM_THREADS 3

//  Before Fixes - A lot of issue when multiple threads are calling this
//  function.
// void *write_to_file(void *arg){
//     const char *thread_name = (const char*) arg;
//     FILE *fp = fopen("A.txt", "a"); // open in append mode.

//     if(fp == NULL){
//         perror("Failed to open file");
//         return NULL;
//     }

//     for(int i = 0; i < 5; i++){
//         fprintf(fp, "%s writing line %d\n", thread_name, i);
//         usleep(1000); // simulating a delay
//     }
//     fclose(fp);
//     return NULL;
// }
//
//

// Fixing the Race conditions using Mutex lock
//
pthread_mutex_t file_lock; // for suynchronizing file access

void *write_to_file(void *arg) {
  const char *thread_name = (const char *)arg;

  // Before open, acqure a lock
  pthread_mutex_lock(&file_lock);
  FILE *fp = fopen("A.txt", "a"); // open in append mode.

  if (fp == NULL) {
    perror("Failed to open file");
    // unlock if failed opening file
    pthread_mutex_unlock(&file_lock);
    return NULL;
  }

  for (int i = 0; i < 5; i++) {
    fprintf(fp, "%s writing line %d\n", thread_name, i);
    usleep(1000); // simulating a delay
  }
  fclose(fp);
  // after closing the file, release the lock now.
  pthread_mutex_unlock(&file_lock);
  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];
  const char *names[] = {"T!", "T2", "T3"};

  // init a lock here
  pthread_mutex_init(&file_lock, NULL);
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_create(&threads[i], NULL, write_to_file, (void *)names[i]);
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  //  finally fone.
  // Destroy the lock
  pthread_mutex_destroy(&file_lock);

  printf("done with writitn got A.txt");
  return 0;
}
