#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    unsigned long long int previous = 0;
    unsigned long long int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    int fiboList[n + 1];
    fiboList[0] = 0;
    fiboList[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        fiboList[i] = (fiboList[i - 1] + fiboList[i - 2])%10;
    }
    return fiboList[n] ;
}


int main() {
    int n;
    std::cin >> n;
    //std::cout << "Naive algorithm: ";
    //int c = get_fibonacci_last_digit_naive(n);
    std::cout  << get_fibonacci_last_digit_fast(n) << std::endl;
    }
