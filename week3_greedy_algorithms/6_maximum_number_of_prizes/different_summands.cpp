#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int myN = n;
  if (n==0||n == 1 || n == 2)
  {
      summands.push_back(n);
    }
  else
  {
      for (int i = 1; i < n + 1;i++)
      {
          myN -= i;
          summands.push_back(i);
          if (myN <= 2 * (i + 1))
          {
              summands.push_back(myN);
              break;
          }
      }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
