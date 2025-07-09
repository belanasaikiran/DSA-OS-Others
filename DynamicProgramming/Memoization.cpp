#include <iostream>
#include <vector>
static int counter = 0;

// We store the calculations in vector and access this if the problem is seen in the pass by storing the answers here.
std::vector<int> memo(100, -1);
// NOTE: We can also use unordered_map for efficiency

int fib(int n){
    counter++;
    if(memo[n] != - 1) return memo[n]; // if exists in memo, grab the answer
    if(n == 0 || n == 1) return n; // these values are run only once for fib(2) and thaat result is stored in memo[2]
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main(){
    std::cout << fib(10) << std::endl;
    std:: cout << "Counter: " << counter << std::endl;
    return 0;
}


// The number of times the fib is called is 0(2n - 1)

// for fib(10) -> 2*10 - 1 = 20 - 1 = 19
