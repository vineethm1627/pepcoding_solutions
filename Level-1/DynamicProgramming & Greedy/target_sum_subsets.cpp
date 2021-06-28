#include <bits/stdc++.h>
using namespace std;

bool targetSum(int *arr, int n, int target) {
    // every element has 2 choices: include or exlcude
    // 2D dp array: {array elements + 1, target + 1}
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            // base case: first cell
            if(i == 0 && j == 0)
                dp[i][j] = true;
            // first row
            else if(i == 0)
                dp[i][j] = false;
            // first column
            else if(j == 0)
                dp[i][j] = true;
            else {
                // the element is not included if target is achieved by earlier items
                if(dp[i - 1][j] == true)
                    dp[i][j] = true;
                // the element is included if earlier items make the remaining target sum
                else {
                    // 1 based indexing in dp table
                    int cur_val = arr[i - 1];
                    // the current element could be picked
                    if(cur_val <= j) {
                        if(dp[i - 1][j - cur_val] == true)
                            dp[i][j] = true;
                    }
                }
            }
        }
    }
    // return are we able to get target sum given all the elements of the set
    return dp[n][target];
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int target;
    cin >> target;
    
    if(targetSum(arr, n, target))
        cout << "true";
    else
        cout << "false";
        
    return 0;
}