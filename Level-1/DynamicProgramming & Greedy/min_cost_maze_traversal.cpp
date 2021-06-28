#include <bits/stdc++.h>
using namespace std;

int minCost(int **matrix, int rows, int cols) {
    // dp[i][j] is the min cost to reach the destination from matrix[i][j]
    // solve from bottom right to top left
    vector<vector<int>> dp(rows, vector<int>(cols));

    for(int i = rows - 1; i >= 0; i--) {
        for(int j = cols - 1; j >= 0; j--) {
            // base case: fill the last cell
            if(i == rows - 1 && j == cols - 1)
                dp[i][j] = matrix[i][j];
            // last row: can go to right(horizontally)only
            else if(i == rows - 1)
                dp[i][j] = dp[i][j + 1] + matrix[i][j];
            // last col: can move down(vertically) only
            else if(j == cols - 1)
                dp[i][j] = dp[i + 1][j] + matrix[i][j];
            else {
                // we have 2 options
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + matrix[i][j];
            }
        }
    }
    // return the cost to go from [0, 0] to bottom right
    return dp[0][0];
}

int main() {
    
    int rows, cols;
    cin >> rows >> cols;
    
    // take user input for matrix
    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }
    
    cout << minCost(matrix, rows, cols);
    
    return 0;
}