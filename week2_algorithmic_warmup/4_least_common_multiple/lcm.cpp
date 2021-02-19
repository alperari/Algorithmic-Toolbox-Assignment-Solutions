#include <iostream>
#include <chrono>

unsigned long long int lcm_naive(int a, int b) {
  for (unsigned long long int l = 1; l <= (unsigned long long int) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (unsigned long long int) a * b;
}

// gcd * lcm = a*b
 unsigned long long int gcd_fast(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_fast(b, a % b);


}



int main() {
  unsigned long long int a, b;
  std::cin >> a >> b;
  unsigned long long int prod = a * b;
  std::cout << prod/gcd_fast(a, b) << std::endl;
  





  return 0;
}
