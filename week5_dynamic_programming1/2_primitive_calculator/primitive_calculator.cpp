#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

map<int, pair<int,int>> dict;
/*
vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

*/

pair<int,int> recursiveSolution(int m)
{
    pair<int,int> ret = make_pair(0,0);
    if (m == 1)
    {
        return make_pair(1, -1);
    }
    if (dict.count(m) != 0)
    {
        return dict[m];
    }
    pair<int, int> ans = make_pair(recursiveSolution(m - 1).first+1, m -1);

    if (m % 3 == 0)
    {
        ret = recursiveSolution(m / 3);
        if (ans.first > ret.first)
        {
            ans = make_pair(ret.first + 1, m / 3);
        }
    }
    if (m % 2 == 0)
    {
        ret = recursiveSolution(m / 2);
        if (ans.first > ret.first)
        {
            ans = make_pair(ret.first + 1, m / 2);
        }
    }
    
    dict[m] = ans;
    return ans;
}

void PrintPath(int m)
{
    vector<int> seq;
    while (recursiveSolution(m).second != -1)
    {
        seq.push_back(m);
        m = recursiveSolution(m).second;
    }
    seq.push_back(1);
    reverse(seq.begin(),seq.end());
    for (int& a : seq)
    {
        cout << a << " ";
    }
}

/*int min_num_operations(int m)
{
    
    
    int dataArr[m + 1];
    dataArr[0] = 0;
    dataArr[1] = 0;
    if (m == 0 || m == 1)
    {
        return dataArr[m];
    }
    dataArr[2] = 1;
    dataArr[3] = 1;

    int num = 1;
    vector<int> v3;
    

    for (int i = 4; i < m + 1 && num <= m; i++)
    {
        myvec.push_back(num);


        if (i % 2 == 0 && i % 3 == 0)
        {
            
            v3.push_back(dataArr[i - 1]) ;
            v3.push_back( dataArr[i / 2]) ;
            v3.push_back( dataArr[i / 3]) ;
            dataArr[i] = *min_element(v3.begin(), v3.end()) + 1;


            
        }
        else if (i % 2 == 0 && i % 3 != 0)
        {

            v3.push_back(dataArr[i - 1]);
            v3.push_back(dataArr[i / 2]);
            dataArr[i] = *min_element(v3.begin(), v3.end()) + 1;

            
        }

        else if (i % 2 != 0 && i % 3 == 0)
        {

            v3.push_back(dataArr[i - 1]);
            v3.push_back(dataArr[i / 3]);
            dataArr[i] = *min_element(v3.begin(), v3.end()) + 1;
            

        }
        else
        {
            dataArr[i] = dataArr[i - 1]+1;
            num += 1;
        }
        


    }
    myvec.push_back(num);

    for (int& item : dataArr)
    {
        cout << item << " ";
    }
    cout << endl;
    for (int& item : myvec)
    {
        cout << item << " ";
    }
    cout << endl;
    return dataArr[m];
}
*/



int main() {
  int n;
  cin >> n;
  
  for (int m = 1; m < n; m++)
  {
      recursiveSolution(m).first;
  }   
  cout << recursiveSolution(n).first-1 <<endl;
  PrintPath(n);

}
