#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int>& w) {
    //write your code here
    vector<vector<int>> matrix(w.size() + 1, vector<int>(W + 1));


    for (int i = 0; i < w.size() + 1; i++)
    {
        matrix[i][0] = 0;
    }
    for (int i = 0; i < W + 1;i++)
    {
        matrix[0][i] = 0;

    }
    int weight = 0;
    for (int i = 1; i < matrix.size(); i++)
    {
        weight = w[i - 1];

        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (j < weight)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else if (j == weight)
            {
                matrix[i][j] = weight;
            }
            else
            {

                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - weight] + weight);
            }
        }
    }
    /*for (int i = 0; i < w.size() + 1;i++)
    {

        for (int j = 0; j < W + 1; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/
    



    return matrix[w.size()][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());
    std::cout << optimal_weight(W, weights) << '\n';
}
