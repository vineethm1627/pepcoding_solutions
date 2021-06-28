#include <bits/stdc++.h>
using namespace std;

// Two 1D arrays
// dpS[i] ways to arrange buildings in plot length i ending with space
// dpB[i] ways to arrange buildings in plot length i ending with Building
long long int arrangeBuildings(int n) {
    // length 1
    int prev_count_S = 1, prev_count_B = 1;
    int cur_count_S, cur_count_B;
    // calculations for single lane
    for(int i = 2; i <= n; i++) {
        cur_count_S = prev_count_S + prev_count_B;
        cur_count_B = prev_count_S;
        // update values
        prev_count_S = cur_count_S;
        prev_count_B = cur_count_B;
    }
    long long int total = cur_count_S + cur_count_B;
    // for every permutation in lane-1, there would be "total" number of permutations in lane-2
    // return the answer for both the lanes combined
    return total * total;
}

int main() {
    
    int n;
    cin >> n;
    
    cout << arrangeBuildings(n);
    
    return 0;
}