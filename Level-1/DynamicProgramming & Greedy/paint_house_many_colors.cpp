#include <bits/stdc++.h>
using namespace std;

// include / exclude concept
// no 2 adjacent houses can have the same color
int minCostPaint(vector<vector<int>> &arr, int rows, int cols) {
    // houses x colors
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    // base case: first row
    for(int j = 0; j < cols; j++)
        dp[0][j] = arr[0][j];
    
    for(int i = 1; i < rows; i++) {
        // ith house jth color
        for(int j = 0; j < cols; j++) {
            // find the min value of all the colors except the jth color
            int min_val = INT_MAX;
            for(int k = 0; k < cols; k++) {
                if(k != j)
                    min_val = min(min_val, dp[i - 1][k]);
            }
            // assign the min value to dp vector
            dp[i][j] = min_val + arr[i][j];
        }
    }
    // return min value of the last row of values
    return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> arr(n, vector<int> (k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++)
            cin >> arr[i][j];
    }
    
    cout << minCostPaint(arr, n, k);
    
    return 0;
}