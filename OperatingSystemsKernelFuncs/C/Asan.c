#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void AccessOutOfBounds() {
  int *intArray;
  intArray = malloc(10 * sizeof(int));
  // intArray[INT32_MAX] = 2;
}

void IterateItems() {
  int arrayLength = 10;
  int *intArray = malloc(10 * sizeof(int));
  for (int i = 0; i <= arrayLength;
       ++i) { // Mistake is accessing the element after last(the = part)
    intArray[i] = 5;
  }
}

int main() {
  // we have two issues in this code
  // // you can find the issue if you compile with address sanitization turned on ( -fsanitize=address)
  AccessOutOfBounds();
  IterateItems();
  return 0;
}
