#include <iostream>
#include <vector>

static int counter = 0;

int fib(int n) {
  std::vector<int> fibList(n+1);
  fibList[0] = 0;
  fibList[1] = 1;

  for (int index = 2; index <= n; index++) {
    counter++;
    fibList[index] = fibList[index - 1] + fibList[index - 2];
  }

  return fibList[n];
}

int main() {
  std::cout << fib(10) << std::endl;
  std::cout << "Counter: " << counter << std::endl;
  return 0;
}

// This is just 0(n-1)
