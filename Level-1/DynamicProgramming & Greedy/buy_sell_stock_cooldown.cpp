#include <bits/stdc++.h>
using namespace std;

// infinite transactions but have to cool down for 1 day after 1 transaction: bs c bs c bs c .....
// buy occurs after cooldown
// there should be a gap of 1 day between prev sell and the current buy
// similar to include/exclude concept
// bsp: bought state profit: bsbsbs....b (ends with b) ie. you have 1 extra share
// ssp: sold state profit: bsbsbs....s (ends with s) ie. you have all transactions in pairs
// csp: cool down state profit: ready to buy again (cool down is done)
int maxProfitCoolDown(int *prices, int n) {
    int prev_bsp = -prices[0]; // the first day stock is bought
    int prev_ssp = 0; // you can't sell without buying
    int prev_csp = 0; // no cooldown as no transaction is done
    int cur_bsp, cur_ssp, cur_csp;
    
    for(int i = 1; i < n; i++) {
        // ending with b: 1 extra share; can be bought after cooldown
        cur_bsp = max(prev_bsp, prev_csp - prices[i]);
        // ending with s: all transactions in pair
        cur_ssp = max(prev_ssp, prev_bsp + prices[i]);
        // cooldown: occurs after selling
        cur_csp = prev_ssp;
        
        // update variables
        prev_bsp = cur_bsp;
        prev_ssp = cur_ssp;
        prev_csp = cur_csp;
    }
    return cur_ssp;
}

int main() {
    
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    
    cout << maxProfitCoolDown(prices, n);
    
    return 0;
}