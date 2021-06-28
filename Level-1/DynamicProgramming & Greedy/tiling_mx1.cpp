#include <bits/stdc++.h>
using namespace std;

// we have an infinite supply of m x 1 tiles
// we have to tile a floor m x n
// source to destination ways based question
// there are only 2 ways: put the tile horizontally/ vertically
int waysTiling(int m, int n) {
    vector<int> dp(n + 1, 0);
    // i represents the width
    // dp[i] tells the number of ways to tile a floor m x i
    for(int i = 1; i <= n; i++) {
        // vertical stacking is the only option
        if(i < m) 
            dp[i] = 1;
        // 2 options: all stacked either vertically or horizontally
        else if(i == m)
            dp[i] = 2;
        else {
            // combination of vertical and horizontal stacking
            int vertical = dp[i - 1];
            int horizontal = dp[i - m];
            dp[i] = vertical + horizontal;
        }
    }
    // number of ways to tile a floor m x n
    return dp[n]; 
} 

int main() {
    
    int n, m;
    cin >> n >> m;
    
    cout << waysTiling(m, n);
    
    return 0;
}