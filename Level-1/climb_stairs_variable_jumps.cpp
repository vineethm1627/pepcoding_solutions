#include <bits/stdc++.h>
using namespace std;

int cs(int arr[], int n){
    // write your code here
    // dp[i] implies the number of ways to go from i to the nth stair(destination)
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // fill the dp table from right to left. dp[n] = 1; n to n is only 1 way
    // base case
    dp[n] = 1; 
    
    for(int i = n - 1; i >= 0; i--) {
        // ways to go from i to n
        // possible positions to reach from the current pos [based on jumps]
        for(int j = 1; j <= arr[i] && (i + j <= n); j++) {
            dp[i] += dp[i + j];
        }
    }
    // number of ways to go from 0 to n
    return dp[0];
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}