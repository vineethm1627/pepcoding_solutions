#include <bits/stdc++.h>
using namespace std;

// two transactions allowed
int maxProfit(int *prices, int n) {
    // to store profits
    int dp[n];
    memset(dp, 0, sizeof(dp));
    // it is mandatory to buy on the ith day [right to left traversal]
    // find the max profit if the stock needs to be bought today and sold after ith day
    // strategy: buy the stock on the ith day and sell it on the max value on the right
    // aaj buy, sell(max value from right) in the future
    // max value of stock so far
    int max_val = prices[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        max_val = max(max_val, prices[i]);
        // max profit if bought today or after today
        dp[i] = max(dp[i + 1], max_val - prices[i]);
    }
    // it is mandatory to sell on the ith day [left to right traversal]
    // find the max profit if the stock needs to be sold before or on ith day
    // strategy: buy the least from the left side and find max val if sold today
    // pehle buy(min value from left), sell today
    // least value of stock so far
    int least_val = prices[0];
    // max profit sold upto today
    for(int i = 1; i < n; i++) {
        least_val = min(least_val, prices[i]);
        // max profit if sold today or before today (upto today)
        dp[i] = max(dp[i - 1], dp[i] + prices[i] - least_val);
    }
    
    return dp[n - 1];
}

int main() {
    
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    
    cout << maxProfit(prices, n);
    
    return 0;
}