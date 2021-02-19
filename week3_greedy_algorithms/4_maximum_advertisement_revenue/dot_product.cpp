#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<long> a, vector<long> b) {
  // write your code here
  long long result = 0;
  while (a.size() != 0)
  {
      int maxElementIndex = std::max_element(a.begin(), a.end()) - a.begin();
      int maxElement = *std::max_element(a.begin(), a.end());


      int maxElementIndex2 = std::max_element(b.begin(), b.end()) - b.begin();
      int maxElement2 = *std::max_element(b.begin(), b.end());
      
      //std::cout << "not adding " << maxElement << " and " << maxElement2 << std::endl;
      result += a[maxElementIndex] * b[maxElementIndex2];
      
      
      a.erase(a.begin() + maxElementIndex);
      b.erase(b.begin() + maxElementIndex2);

  
  }
  
  
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
