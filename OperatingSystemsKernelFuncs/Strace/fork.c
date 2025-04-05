#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>


void fork_example(){

  if(fork() == 0){
    printf("Hello from Child!\n");
  } else{
    printf("hello from parent!\n");
  }
}


int main(){
  fork_example();
  return 0;
}
