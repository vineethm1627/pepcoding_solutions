#include <bits/stdc++.h>
using namespace std;

// include / exclude concept
// r means this house is painted red only
// b means this house is painted blue only
// g means this house is painted green only
// no 2 adjacent houses can have the same color
int minCostPaint(vector<vector<int>> &arr, int n) {
    int prev_r = arr[0][0], prev_b = arr[0][1], prev_g = arr[0][2];
    int cur_r, cur_b, cur_g;
    
    for(int i = 1; i < n; i++) {
        cur_r = min(prev_g, prev_b) + arr[i][0];
        cur_b = min(prev_g, prev_r) + arr[i][1];
        cur_g = min(prev_r, prev_b) + arr[i][2];
        
        // update variables
        prev_r = cur_r;
        prev_b = cur_b;
        prev_g = cur_g;
    }
    return min({cur_b, cur_g, cur_r});
}

int main() {
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int> (3));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    
    cout << minCostPaint(arr, n);
    
    return 0;
}