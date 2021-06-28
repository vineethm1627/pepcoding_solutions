#include <bits/stdc++.h>
using namespace std;

// every element has 2 choices: include / exclude
// max sum upto i including / exluding the ith element
int maxSumNonAdj(int *arr, int n) {
    int prev_incl = arr[0], prev_excl = 0;
    int cur_incl, cur_excl;
    
    for(int i = 1; i < n; i++) {
        cur_incl = prev_excl + arr[i];
        cur_excl = max(prev_incl, prev_excl);
        // update the variables
        prev_incl = cur_incl;
        prev_excl = cur_excl;
    }
    return max(cur_excl, cur_incl);
}

int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxSumNonAdj(arr, n);
    
    return 0;
}