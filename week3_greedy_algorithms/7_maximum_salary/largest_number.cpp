#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isGreater(string a, string b)
{
    int first = 0;
    int second = 0;

    string str1 = a + b;
    std::stringstream mystream1(str1);
    mystream1 >> first;

    string str2 = b + a;
    std::stringstream mystream2(str2);
    mystream2 >> second;

    if (first >= second)
    {
        return true;
    }
    return false;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  
  string result;
  string max_digit;
  int index_to_remove = 0;
  while (a.size() != 0)
  {
      max_digit = "0";
      for (int i = 0; i < a.size(); i++)
      {
          if (isGreater(a[i], max_digit))
          {
              max_digit = a[i];
              index_to_remove = i;
          }
      }
      result += max_digit;
      a.erase(a.begin() + index_to_remove);
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
