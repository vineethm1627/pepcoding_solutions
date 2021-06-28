#include <bits/stdc++.h>
using namespace std;

int maxProfitK(int *prices, int n, int k) {
    // 2D dp {transactions x days}
    // dp[i][j] :max profit if upto day j, atmost i transactions are allowed: we store the profits in the dp vector
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
    // loop for transaction
    for(int t = 1; t <= k; t++) {
        // loop for days
        for(int d = 1; d < n; d++) {
            // t transactions done on prev day: continue that
            int max_val = dp[t][d - 1];
            // t - 1 transactions one day before and make a transaction today (t th transaction)
            for(int prev_d = 0; prev_d < d; prev_d++) {
                // profit till d - 1 th day for t-1 transactions
                int cur_profit = dp[t - 1][prev_d];
                // if t th transaction is made {buy:prev_d -> sell:d}
                int next_profit = prices[d] - prices[prev_d];
                // find out the max profit
                if(cur_profit + next_profit > max_val)
                    max_val = cur_profit + next_profit;
            }
            // store the max profit 
            dp[t][d] = max_val;
        }
    }
    return dp[k][n - 1];
}

int main() {
    
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++) 
        cin >> prices[i];
    
    int k;
    cin >> k;
    
    cout << maxProfitK(prices, n, k);
    
    return 0;
}