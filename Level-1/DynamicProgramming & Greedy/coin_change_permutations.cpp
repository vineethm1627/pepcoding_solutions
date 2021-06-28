#include <bits/stdc++.h>
using namespace std;

int coinPermutations(int*coins, int n, int amount) {
    // dp[i] is the number of permutations to get value i, using all coins
    // start solving from left to right
    vector<int> dp(amount + 1, 0);
    // base case
    dp[0] = 1;
    // outer loop is to traverse the dp array: go through all the coins for each amount value {vice-versa was done in coin combinations}
    for(int i = 1; i <= amount; i++) {
        // go through all the coins
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i)
                dp[i] += dp[i - coins[j]];
        }
    }
    // return number of permutations to get value 'amount'
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
    
    cout << coinPermutations(coins, n, amount);
    
    return 0;
}