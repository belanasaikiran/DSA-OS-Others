// - If given multiple resources (differnt resources) and multiple clients, how would you make sure that there won't be any race conditions.
// 	1. Function to acquire lock and return a handler
//
//

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_RESOURCES 5

typedef struct{
    int id;
} Resource;


Resource resource_pool[NUM_RESOURCES];
pthread_mutex_t resource_locks[NUM_RESOURCES];

void init_resources(){
    for(int i = 0; i < NUM_RESOURCES; i++){
        resource_pool[i] = i;
        pthread_mutex_init(&resource_locks[i], NULL);
    }
}

void acquire_resource(int handler){
    for(int i = 0; i < NUM_RESOURCES; i++){
        resource_pool[i].id = i;
        pthread_mutex_init(&resource_lock[i], NULL);
    }

}
