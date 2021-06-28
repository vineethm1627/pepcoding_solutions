#include <bits/stdc++.h>
using namespace std;

// count combinations only
long long int kSubsetsPartition(int n, int k) {
    //2D dp {number of groups x number of people}
    vector<vector<long long int>> dp(k + 1, vector<long long int>(n + 1, 0));
    
    for(int g = 1; g <= k; g++) {
        // ways to arrange p people in g non-empty groups
        for(int p = 1; p <= n; p++) {
            // number of people are lesser than number of groups
            if(p < g)
                dp[g][p] = 0;
            // one person in each group
            else if(p == g)
                dp[g][p] = 1;
            else {
                // formula
                dp[g][p] = dp[g - 1][p - 1] + g * dp[g][p - 1];
            }
        }
    }
    return dp[k][n];
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    cout << kSubsetsPartition(n, k);
    
    return 0;
}