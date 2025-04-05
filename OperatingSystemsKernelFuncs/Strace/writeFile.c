#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("starting program\n");

  int num;
  FILE *file_ptr;

  file_ptr = fopen("my_out.txt", "w");

  if(file_ptr == NULL){
    printf("Error Opening file\n");
    exit(1);
  }

  fprintf(file_ptr, "Hello world!\n");
  fclose(file_ptr);
  printf("Done\n");

  return 0;
}
