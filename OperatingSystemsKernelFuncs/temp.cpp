#include <iostream>
#include <string.h>
using namespace std;

// Write a function in C that copies a string from a source to a destination
// without causing a buffer overflow
int copyString(char *source, char *destination, size_t destination_size) {
  if (!destination || !source || destination_size == 0) {
    return -1;
  }

  size_t i = 0;

  // Approach 1: One better way to copy char by char
  // for(; i < destination_size - 1 && source[i] != '\0';++i){
  //     memmove(&destination[i], &source[i], 1);
  // }
  // //last one ends with null termination
  // destination[i] = '\0';


  //  Approach 2:
  // Other way is to use mem_copy and replace last byte with null terminator
  void *ret = memccpy(destination, source, '\0', destination_size-1);
    if(ret == NULL){
        destination[destination_size - 1] = '\0';
    }

  return 0;
}

int main() {
  char destination_buffer[4];

  char source[] = "Hello World!";

  if (copyString(source, destination_buffer, sizeof(destination_buffer)) == 0) {
    cout << "Success!";
  } else {
    cout << "failed";
  }

  return 0;
}
