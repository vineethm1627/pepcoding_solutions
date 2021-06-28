#include <bits/stdc++.h>
using namespace std;

// Recursion with memoization solution
// source to destination ways based question
// there are only 2 ways: put the tile horizontally/ vertically
int waysTiling(int n, vector<int> &memo) {
    // base case: ways to tile 2 x 1
    if(n == 1)
        return 1;
    // base case: ways to tile 2 x 2: both horizontal + both horizontal
    if(n == 2)
        return 2;
    // memoization: check if result is pre-computed
    if(memo[n] != -1)
        return memo[n];
    // recursive calls
    int vertical = waysTiling(n - 1, memo);
    int horizontal = waysTiling(n - 2, memo);
    
    return memo[n] = vertical + horizontal;
} 

int main() {
    
    int n;
    cin >> n;
    
   // vector<int> memo(n + 1, -1);
   // cout << waysTiling(n, memo);
    
    // DP Solution
    // base case
    int dp1 = 1, dp2 = 2, dp3;
    
    for(int i = 3; i <= n; i++) {
        dp3 = dp1 + dp2;
        dp1 = dp2;
        dp2 = dp3;
    }
    cout << dp3;
    return 0;
}