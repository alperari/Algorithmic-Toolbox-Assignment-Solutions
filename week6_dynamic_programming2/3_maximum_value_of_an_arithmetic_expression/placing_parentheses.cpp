#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;


vector<char> ops;
vector<long long int> nums;



long long int  eval(long long int a, long long int b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
    return 0;
}



vector<long long int > MinAndMax(int i, int j, vector<vector<long long int >>& M, vector<vector<long long int >>& m)
{
    vector<long long int > pair(2);

    long long int  myMin = LLONG_MAX;
    long long int  myMax = LLONG_MIN;
    long long int  a, b, c, d;
    for (int k = i; k < j; k++)
    {
        a = eval(M[i][k], M[k + 1][j], ops[k]);
        b = eval(M[i][k], m[k + 1][j], ops[k]);
        c = eval(m[i][k], M[k + 1][j], ops[k]);
        d = eval(m[i][k], m[k + 1][j], ops[k]);
        myMin = std::min({ a, b, c, d, myMin });
        myMax = std::max({a, b, c, d, myMax});

    }
    pair[0] = myMin;
    pair[1] = myMax;
    return pair;
}



long long int get_maximum_value(const string& exp) {
    //write your code here

    for (int i = 0; i < exp.length();i++)
    {
        if (i % 2 == 0)
            nums.push_back((long long int)exp[i] - '0');
        else
            ops.push_back(exp[i]);


    }
    vector<vector<long long int > > M(nums.size(), vector<long long int >(nums.size(), LLONG_MIN));
    vector<vector<long long int > > m(nums.size(), vector<long long int >(nums.size(), LLONG_MAX));
    int j = 0;
    vector<long long int > returnedPair;
    for (int i = 0; i < nums.size();i++)
    {
        M[i][i] = nums[i];
        m[i][i] = nums[i];
    }
    for (int s = 0; s < nums.size() - 1; s++)
    {
        for (int i = 0; i < nums.size() - s - 1; i++)
        {
            j = i + s + 1;
            returnedPair = MinAndMax(i, j, M, m);
            m[i][j] = returnedPair[0];
            M[i][j] = returnedPair[1];
        }
    }


    
    return M[0][M[0].size() - 1];
}

int main() {
    string s;
    std::cin >> s;
    long long int    r = get_maximum_value(s);
    std::cout << r << '\n';
}
