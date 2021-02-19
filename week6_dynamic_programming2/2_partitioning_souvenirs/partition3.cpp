#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
void printMatrix(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix[0].size();j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int partition3(vector<int> &nums, int sumPerPerson) {
  //write your code here
    vector<vector<int>> matrix(nums.size() + 1, vector<int>(sumPerPerson+1,0));
    /*for (int i = 0; i < matrix.size();i++)
    {
        matrix[i][0] = 0;
    }
    for (int i = 0; i < matrix[0].size();i++)
    {
        matrix[0][i] = 0;
    }
*/
    int value;
    for (int i = 1; i < nums.size() + 1;i++)
    {
        value = nums[i-1];
        for (int j = 1; j < sumPerPerson + 1;j++)
        {
            if (j < value)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else if(j==value)
            {
                matrix[i][j] = value;
            }
            else
            {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - value] + value);
            }
        }
    }

    for (int i = matrix.size() - 1; i > matrix.size() -4;i--)
    {
        //std::cout << matrix[i][matrix[0].size() - 1] << " ";

        if(matrix[i][matrix[0].size()-1] != sumPerPerson)
        {
            return 0;
        }
    }
    
    
    //printMatrix(matrix);




  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum += A[i];
  }
  if (sum % 3 != 0)
  {
      std::cout << "0" << std::endl;
      return 1;
  }
  else
  {
      int sumPerPerson = sum / 3;
      std::sort(A.begin(), A.end());
      std::cout << partition3(A, sumPerPerson) << '\n';
      
      return 0;
  }
  
}
