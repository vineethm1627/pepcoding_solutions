#include <bits/stdc++.h>
using namespace std;

// dig from left to right
int maxGold(vector<vector<int>> &matrix, int rows, int cols) {
    // dp[i][j] stores the max value if you start digging from matrix[i][j]
    // fill the table column wise from right to left
    vector<vector<int>> dp(rows, vector<int>(cols));
    
    for(int j = cols - 1; j >= 0; j--) {
        for(int i = rows - 1; i >= 0; i--) {
            // last col
            if(j == cols - 1)
                dp[i][j] = matrix[i][j];
            // first row: 2 options (top goes out of bound)
            else if(i == 0)
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + matrix[i][j];
            // last row: 2 options (bottom goes out of bound)
            else if(i == rows - 1)
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + matrix[i][j];
            else {
                // 3 options are there
                dp[i][j] = max({dp[i - 1][j + 1], dp[i][j + 1], dp[i + 1][j + 1]}) + matrix[i][j];
            }
        }
    }
    // return the max value in the first column
    int max_val = dp[0][0];
    for(int i = 0; i < rows; i++)
        max_val = max(max_val, dp[i][0]);
    
    return max_val;
}

int main() {
    
    int rows, cols;
    cin >> rows >> cols;
    
    // take user input matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }
    
    cout << maxGold(matrix, rows, cols);
    
    
    return 0;
}