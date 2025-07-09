// Look at the counter to know the number of function calls.
// Try running fib(5), fib(10), fib(20), fib(40), fib(41) and observer the counter
// ***** This is very inefficient. *****
// Check Memoization Implementation or Bottom-Up approach

#include <iostream>

static int counter = 0;


int fib(int n){
    counter++;
    if(n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    std::cout << fib(10) << std::endl;
    std:: cout << "Counter: " << counter << std::endl;
    return 0;
}
