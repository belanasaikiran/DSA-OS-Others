#include<stdio.h>

int main() {
  int array[5];

  for (int i = 0; i <= 5; i++) {
    array[i] = 0 + i;
    printf(array[i]);
  }

  return 0;
}
