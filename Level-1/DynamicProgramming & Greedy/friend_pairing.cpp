#include <bits/stdc++.h>
using namespace std;

// number of ways in which n friends can stay single or pair up
// only combinations required and not permutations
int friendsPairing(int n) {
    // base case
    int dp_1 = 1; // 1 single
    int dp_2 = 2; // each single + 1 pair
    int dp_3;
    
    for(int i = 3; i <= n; i++) {
        dp_3 = dp_2 + (i - 1) * dp_1;
        // update values
        dp_1 = dp_2;
        dp_2 = dp_3;
    }
    return dp_3;
}

int main() {
    
    int n;
    cin >> n;
    
    cout << friendsPairing(n);
    
    return 0;
}