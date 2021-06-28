#include <bits/stdc++.h>
using namespace std;

int countEncodings(string s) {
    int n = s.size();
        // dp[i] total number of encodings for a string of length i
        vector<int> dp(n + 1);
        // base case
        dp[0] = 1; // first char of len 1 has only 1 encoding
        
        for(int i = 1; i <= n; i++) {
            // attach it as a single stand-alone char: extension
            // last 1 char
            if(s[i - 1] != '0')
                dp[i] = dp[i - 1]; 
            else
                dp[i] = 0;
            // last 2 chars
            if(i >= 2) {
                if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n];
}

int main() {

  string s;
  cin >> s;
  cout << countEncodings(s);

  return 0;
}