#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    int count = 0;
    int candidate = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (candidate != a[i] )
        {
            if (count!=0)
            {
                count--;
            }
            else
            {
                candidate = a[i];
                count = 1;
            }
        }
        else
        {
            count++;
        }
    }

    if (!count)
    {
        return -1;
    }
    else
    {
        count = 0;
        for (int i = 0; i < a.size();i++)
        {
            if (a[i] == candidate)
            {
                count++;
            }
        }
        if (count > a.size() / 2)
        {
            return 1;
        }
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
