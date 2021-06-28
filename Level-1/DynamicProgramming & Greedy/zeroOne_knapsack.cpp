#include <bits/stdc++.h>
using namespace std;

// user defined data types
typedef long long int lli;

int knapsack(int W, int *values, int *wts, int n) {
    // items x capacity
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    int pick, dont_pick;
    
    // i --> items
    // j --> capacity weight values
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            dont_pick = dp[i - 1][j];
            pick = 0;
            if(wts[i - 1] <= j)
                // add current item's value and the value of the remaining weight from the prev row
                pick = values[i - 1] + dp[i - 1][j - wts[i - 1]];
            dp[i][j] = max(pick, dont_pick);
        }
    }
    return dp[n][W];
}

int main() {
    
    int n;
    cin >> n;
    
    int values[n];
    for(int i = 0; i < n; i++)
        cin >> values[i];
    
    int wts[n];
    for(int i = 0; i < n; i++)
        cin >> wts[i];
    
    int W;
    cin >> W;
    
    cout << knapsack(W, values, wts, n);
    
    return 0;
}