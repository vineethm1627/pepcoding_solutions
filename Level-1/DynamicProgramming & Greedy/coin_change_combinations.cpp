#include <bits/stdc++.h>
using namespace std;

/*
    if amount = 7, coins = [2, 3, 5]
    Output: 2 as there are only 2 combinations: {2,2,3}, {2,5}
    
    having an outer loop for coins implies we first consider 2, then 3 and then 5: and this is how combinations actually work
*/

int coinCombinations(int *coins, int n, int amount) {
    // dp[i] = number of combinations to pay amount i using all the coins
    // start travelling from left to right
    vector<int> dp(amount + 1, 0);
    // base case: one combination to pay 0 ie. chose nothing
    dp[0] = 1;
    // outer loop is for the coins
    for(int i = 0; i < n; i++) {
        // go through amount dp array
        // first amount that could be paid without resulting in negative is coins[j]
        for(int j = coins[i]; j <= amount; j++) {
            // number of ways to pay amount j
            dp[j] += dp[j - coins[i]];
        }
    }
    // return number of combinations to return value 'amount'
    return dp[amount];
}

int main() {
    
    int n;
    cin >> n;
    
    int coins[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    
    int amount;
    cin >> amount;
    
    cout << coinCombinations(coins, n, amount);
    
    return 0;
}