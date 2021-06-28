#include <bits/stdc++.h>
using namespace std;

// count of binary strings with no consecutive 0s: include/exclude style
// Two 1D arrays
int countBinaryStrings(int n) {
    vector<int> dp0(n + 1, 0), dp1(n + 1, 0);
    // dp0[i] implies count of binary strings without consec 0 ending with 0
    // dp1[i] implies count of binary strings without consec 0 ending with 1
    // base case: there are no strings of 0 length
    //dp0[0] = dp1[0] = 0;
    //dp0[1] = dp1[1] = 1;
    
    // for(int i = 2; i <= n; i++) {
    //     dp1[i] = dp1[i - 1] + dp0[i - 1];
    //     dp0[i] = dp1[i - 1];
    // }
    // return dp0[n] + dp1[n];
    
    // length 1
    int prev_count_0 = 1, prev_count_1 = 1;
    int cur_count_0, cur_count_1;
    
    for(int i = 2; i <= n; i++) {
        cur_count_1 = prev_count_0 + prev_count_1;
        cur_count_0 = prev_count_1;
        
        // update values
        prev_count_0 = cur_count_0;
        prev_count_1 = cur_count_1;
    }
    return cur_count_0 + cur_count_1;
}

int main() {
    
    int n;
    cin >> n;
    
    cout << countBinaryStrings(n);
    
    return 0;
}