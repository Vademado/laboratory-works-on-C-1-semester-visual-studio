#include "sources.hpp"

unsigned fibonacci(int n)
{
    if (n < 1)
        return 0;
    std::vector<int> arr{ 0, 1, 1 };
    for (size_t i = 3; i <= n; ++i)
    {
        arr.push_back(arr[i - 1] + arr[i - 2]);
    }
    return arr[n];
}

unsigned fibonacci_recursive(int n)
{
    if (n < 1)
        return 0;
    if (n < 3)
        return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

void print_answer(unsigned n, unsigned fib_n)
{
    std::cout << n << " the n th fibonacci number:" << fib_n << std::endl;
}