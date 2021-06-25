#include <iostream>
using namespace std;

int cs(int n) {
    // write your code here

    if (n <= 1)
        return 1;
    if(n == 2)
        return 2;
    // There is one way to reach stair 0 ie. do nothing.
    int dp_0 = 1, dp_1 = 1, dp_2 = 2, dp_3;
    
    for(int i = 3; i <= n; i++) {
        dp_3 = dp_0 + dp_1 + dp_2;
        dp_0 = dp_1;
        dp_1 = dp_2;
        dp_2 = dp_3;
    }
    return dp_3;
}

int main() {
    int n;
    cin >> n;
    cout << cs(n) << endl;
}