image we have a function that determines the maximum of two numbers.

```c++
#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}
```

Now, we also want to use it for characters or floating-point numbers. We use function overloading.

```c++
#include <iostream>

char max(char a, char b) {
    return (a > b) ? a : b;
}

float max(float a, float b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}
```

The above code is overloading and does the same thing everywhere.

So, how about we can also specify data types for the function parameters?

This is where function templates come in handy.

```c++
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

To use it, we simply specify the data type of the parameters when calling the function.

```c++
int main(){
    int a = 5, b = 10;
    char c = 'a', d = 'z';
    float e = 3.14, f = 2.71;
    double g = 1.618, h = 0.577;

    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;
    std::cout << "Max of " << c << " and " << d << " is " << max(c, d) << std::endl;
    std::cout << "Max of " << e << " and " << f << " is " << max(e, f) << std::endl;
    std::cout << "Max of " << g << " and " << h << " is " << max(g, h) << std::endl;

    return 0;
}

**What if one of the parameters is double and other is int?**

```c++
    std::cout << "Max of " << a << " and " << g << " is " << max(a, g) << std::endl;
```

We can use the `auto` keyword to automatically deduce the return type.
or we can use the `decltype` keyword to specify the return type explicitly.
Either `T` or `U` can be used as the return type.

```c++
template <typename T, typename U>
auto max(T a, U b) {
    return (a > b) ? a : b;
}
