#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;

struct item
{
    int weight;
    int value;
    double perUnit;
    item(int x, int y): weight(x), value(y), perUnit((double)y/x) {}

    bool operator < (const item& str) const
    {
        return (perUnit < str.perUnit);
    }
};

double get_optimal_value(int capacity, vector<item> items) {
  double MAXvalue = 0.0;
  int a = 0;
  for (int i = 0;i < items.size();i++)
  {
      if (capacity == 0)
      {
          return MAXvalue;
      }
      a = std::min( items[i].weight, capacity );
      MAXvalue += a * items[i].perUnit;
      items[i].weight -= a;
      capacity -= a;

  }

  return MAXvalue;
}

int main() {
  int n;
  int capacity;
  
  std::cin >> n >> capacity;
  
  vector<item> items;

  int x = 0;
  int y = 0;

  for (int i = 0; i < n; i++) {
      std::cin >> x >> y;
      items.push_back(item(y,x));
  }
  std::sort(items.rbegin(), items.rend());

  double optimal_value = get_optimal_value(capacity, items);
  /*for (auto& item : items)
  {
      std::cout << item.perUnit << std::endl;
  }*/
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
