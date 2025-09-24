#include <iostream>
#include <vector>

//ToDo: Clean up this mess

long long fibonacci(int n, std::vector<long long>& memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Input an integer: ";
    std::cin >> n;

    std::vector<long long> memo(n + 1, -1);

    std::cout << "Fibonacci digits: ";
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i, memo) << " ";
    }
    std::cout << std::endl;

    return 0;
}