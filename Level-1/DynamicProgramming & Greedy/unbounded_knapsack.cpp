#include <bits/stdc++.h>
using namespace std;

// user defined data types
typedef long long int lli;

// duplicate items are allowed: 1D DP
int unbounded_knapsack(int W, int *values, int *wts, int n) {
    // dp[i] indicates the max profit for capacity i
    int dp[W + 1];
    dp[0] = 0;
    // dp[0] = 0, implies a bag of capacity 0 ie. bag doesn't exist
    int max_val = 0;
    // go through the weight capacity values: dp table from left to right
    for(int i = 1; i <= W; i++) {
        // go through all the items
        max_val = 0;
        for(int j = 0; j < n; j++) {
            // item could only be picked if its weight <= capacity i
            if(wts[j] <= i)
                max_val = max(max_val, values[j] + dp[i - wts[j]]);
        }
        dp[i] = max_val;
    }
    return dp[W];
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
    
    cout << unbounded_knapsack(W, values, wts, n);
    
    return 0;
}