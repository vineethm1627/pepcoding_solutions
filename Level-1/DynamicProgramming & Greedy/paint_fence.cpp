#include <bits/stdc++.h>
using namespace std;

// permutations and include/ exclude based questions
// number of ways to paint fence, no more than 2 consecutive fences have the same color
// n fences and k colors are given
// same: last two fences have the same color
// diff: last two fences don't have the same color
// total: sum of the above 2 values {same, diff}
long long int waysPaintFence(int n, int k) {
    // base case: fence of length 2
    long long int same = k * 1; // k options for place 1, same col for place 2
    long long int diff = k * (k - 1);
    long long int total = same + diff;
    
    for(int i = 3; i <= n; i++) {
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total;
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    cout << waysPaintFence(n, k);
    
    return 0;
}