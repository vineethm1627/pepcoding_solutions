#include <bits/stdc++.h>
using namespace std;

// infinite transactions are allowed, buy we need to pay the fee on the day of selling the stock
// similar to include/exclude concept
// bsp: bought state profit: bsbsbs....b (ends with b) ie. you have 1 extra share
// ssp: sold state profit: bsbsbs....s (ends with s) ie. you have all transactions in pairs
int maxProfit(int *prices, int fee, int n) {
    int prev_bsp = -prices[0]; // the first day stock is bought
    int prev_ssp = 0; // you can't sell without buying
    int cur_bsp, cur_ssp;
    
    for(int i = 1; i < n; i++) {
        // ending with b: 1 extra share
        cur_bsp = max(prev_bsp, prev_ssp - prices[i]);
        // ending with s: all transactions in pair
        cur_ssp = max(prev_ssp, prices[i] - fee + prev_bsp);
        
        // update variables
        prev_bsp = cur_bsp;
        prev_ssp = cur_ssp;
    }
    return cur_ssp;
}

int main() {
    
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    
    int fee;
    cin >> fee;
    
    cout << maxProfit(prices, fee, n);
    
    return 0;
}