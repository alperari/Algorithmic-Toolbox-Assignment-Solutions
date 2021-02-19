#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int>& a, vector<int>& b, vector<int>& commons) {
    //write your code here
    commons.clear();
    vector<vector<int>> DP_Table(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i < a.size() + 1;i++)
    {
        for (int j = 0; j < b.size() + 1;j++)

            DP_Table[i][j] = 0;
    }

    if (a.size() == 1 && b.size() == 1)
    {
        if (a[0] == b[0])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (a.size() == 1)
    {
        for (int i = 0; i < b.size();i++)
        {
            if (a[0] == b[i])
            {
                return 1;
            }
        }
        return 0;
    }
    if (b.size() == 1)
    {
        for (int i = 0; i < a.size();i++)
        {
            if (b[0] == a[i])
            {
                return 1;
            }
        }
        return 0;
    }


    for (int i = 1; i < a.size() + 1;i++)
    {
        for (int j = 1; j < b.size() + 1;j++)
        {
            DP_Table[i][j] = std::max(DP_Table[i - 1][j], DP_Table[i][j - 1]);

            if (a[i - 1] == b[j - 1])
            {
                DP_Table[i][j] = DP_Table[i - 1][j - 1] + 1;
            }



        }
    }
    /* 
    for (int i = 0; i < DP_Table.size();i++)
    {
        for (int j = 0; j < DP_Table.size();j++)
        {
            std::cout << DP_Table[i][j];
        }
        std::cout << std::endl;
    }*/
   


    //for printing the common subseq
    int i = a.size();
    int j = b.size();
    while (i >= 1 && j >= 1)
    {
        if (DP_Table[i - 1][j] == DP_Table[i][j - 1] && DP_Table[i][j] == DP_Table[i - 1][j - 1] + 1)
        {
            commons.push_back(b[j - 1]);
            i--;
            j--;
        }
        else if (DP_Table[i][j] == DP_Table[i][j - 1])
        {
            j--;
        }
        else if (DP_Table[i][j] == DP_Table[i - 1][j])
        {
            i--;
        }
    }
    std::reverse(commons.begin(), commons.end());
    return DP_Table[a.size()][b.size()];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    vector<int> commons;
    std::cout << lcs2(a, b, commons) << std::endl;
    /*
    std::cout << std::endl;

    for (int& a : commons)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;*/
    
    
}
