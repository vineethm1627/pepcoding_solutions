#include <iostream>
using namespace std;

void printDecreasing(int n) {
    // base case
    if(n == 0)
        return;
    cout << n << endl;
    // recursive call
    printDecreasing(n - 1);
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}
