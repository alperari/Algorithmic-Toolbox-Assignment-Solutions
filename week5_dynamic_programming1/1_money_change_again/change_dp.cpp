#include <iostream>

int get_change(int m) {
    int coins[3] = { 1,3,4 };

    int dataArray[m + 1];
    for (int& data : dataArray)
    {
        data = m + 1;
    }

    dataArray[0] = 0;
    int minNum = 0;
    for (int coin : coins)
    {
        //std::cout << coin << "       ";
        for (int i = 0; i < m + 1;i++)
        {
            if (i >= coin)
            {
                minNum = dataArray[i-coin] + 1;
                if (minNum < dataArray[i])
                {
                    dataArray[i] = minNum;
                }
                    
            }
            //std::cout << dataArray[i] << " ";
        }
        //std::cout << std::endl;
    }


    return dataArray[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
