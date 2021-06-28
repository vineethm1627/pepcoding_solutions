#include <bits/stdc++.h>
using namespace std;

// user defined data types
typedef long long int lli;

int maxProfit(int *prices, int n) {
    int max_profit = 0, min_val = prices[0];
    
    for(int i = 1; i < n; i++) {
        // buy the stock
        if(prices[i] < min_val)
            min_val = prices[i];
        // sell the stock
        else
            max_profit = max(max_profit, prices[i] - min_val);
    }
    return max_profit;
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