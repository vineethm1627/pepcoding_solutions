#include <bits/stdc++.h>
using namespace std;

// user defined data types
typedef long long int lli;

int maxProfit(int *prices, int n) {
    int buy_date = 0, sell_date = 0, max_profit = 0;
    
    for(int i = 1; i < n; i++) {
        // increase the selling date: up stroke
        // hold the stock
        if(prices[i] > prices[i - 1])
            sell_date++;
        // sell the stock: down stroke
        else {
            max_profit += prices[sell_date] - prices[buy_date]; 
            // reset the dates
            buy_date = sell_date = i;
        }
    }
    // last up stroke
    max_profit += prices[sell_date] - prices[buy_date];
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