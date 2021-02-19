#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

    vector<vector<int>> DP_Table(str1.length()+1, vector<int>(str2.length()+1));
    for (int i = 0; i < str1.length() + 1;i++)
    {
        DP_Table[i][0] = i;
    }
    for (int i = 0; i < str2.length() + 1;i++)
    {
        DP_Table[0][i] = i;
    }

    for (int i = 1; i < str1.length() + 1;i++)
    {
        for (int j = 1; j < str2.length() + 1;j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                DP_Table[i][j] = DP_Table[i - 1][j - 1];
            }
            else
            {
                DP_Table[i][j] = std::min({ DP_Table[i - 1][j - 1], DP_Table[i - 1][j], DP_Table[i][j - 1] }) + 1;
            }
        }

    }

  return DP_Table[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
