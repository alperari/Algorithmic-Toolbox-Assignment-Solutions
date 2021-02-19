#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;




int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
    
    vector<vector<vector<int>>> table(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));
    for (int x = 0; x < a.size() + 1;x++)
    {
        for (int y = 0; y < b.size() + 1;y++)
        {
            for (int z = 0; z < c.size() + 1;z++)
            {
                table[x][y][z] = 0;
            }
        }
    }
    for (int x = 1; x < a.size() + 1;x++)
    {
        for (int y = 1; y < b.size() + 1;y++)
        {
            for (int z = 1; z < c.size() + 1;z++)
            {
                table[x][y][z] = std::max({ table[x][y - 1][z], table[x - 1][y][z], table[x][y][z - 1] });

                //std::cout << "NOW X: " << a[x - 1] << "  NOW Y:" << b[y - 1] << " NOW Z" << c[z - 1] << std::endl;
                if (a[x - 1] == b[y - 1] && b[y - 1] == c[z - 1])
                {
                    table[x][y][z] = table[x - 1][y - 1][z - 1] + 1;
                }
            }
        }
    }
    /*vector<vector<int>> DP_Table(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i < a.size() + 1;i++)
    {
        for (int j = 0; j < b.size() + 1;j++)
        s
            DP_Table[i][j] = 0;
    }

    if (a.size() == 1 && b.size() == 1)
    {
        if (a[0] == b[0])
        {
            commons.push_back(a[0]);
            return commons;
        }
        else
        {

            return commons;
        }
    }

    if (a.size() == 1)
    {
        for (int i = 0; i < b.size();i++)
        {
            if (a[0] == b[i])
            {
                commons.push_back(a[0]);
                return commons;
            }
        }
        return commons;
    }
    if (b.size() == 1)
    {
        for (int i = 0; i < a.size();i++)
        {
            if (b[0] == a[i])
            {
                commons.push_back(b[0]);
                return commons;
            }
        }
        return commons;
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

    for (int i = 0; i < DP_Table.size();i++)
    {
        for (int j = 0; j < DP_Table.size();j++)
        {
            std::cout << DP_Table[i][j];
        }
        std::cout << std::endl;
    }



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


    for (int x = 0; x < a.size() + 1;x++)
    {
        std::cout << "for x=" << x <<  std::endl;
        for (int y = 0; y < b.size() + 1;y++)
        {
            for (int z = 0; z < c.size() + 1;z++)
            {
                std::cout << table[x][y][z] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    */
    return table[a.size()][b.size()][c.size()];
}



int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }


    std::cout << lcs3(a, b, c);
}
