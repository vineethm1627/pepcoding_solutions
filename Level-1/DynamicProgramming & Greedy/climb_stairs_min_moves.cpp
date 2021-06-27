#include <bits/stdc++.h>
using namespace std;

int minMoves(int *arr, int n) {
    // dp[i] indicates the min moves needed to reach n from ith position
    vector<int> dp(n + 1, INT_MAX);
    // reach n from n will take no moves
    dp[n] = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > 0) {
            int min_jumps = INT_MAX;
            for(int j = 1; j <= arr[i] && (i + j <= n); j++) 
                min_jumps = min(min_jumps, dp[i + j]);
            // add one for the current step
            if(min_jumps != INT_MAX)
                dp[i] = min_jumps + 1;
        }
    }
    return dp[0];
}

int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << minMoves(arr, n);
    
    return 0;
}