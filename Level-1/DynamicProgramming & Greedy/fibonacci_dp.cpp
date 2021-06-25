#include <iostream>
using namespace std;

int fib(int n){
    // write your code here
    if(n <= 1)
        return n;
    
    int dp_0 = 0, dp_1 = 1, dp_2;
    
    for(int i = 2; i <= n; i++) {
        dp_2 = dp_1 + dp_0;
        dp_0 = dp_1;
        dp_1 = dp_2;
    }
    return dp_2;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}