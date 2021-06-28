#include <bits/stdc++.h>
using namespace std;

// include/ exclude concept
// sub_a : the number of subsequences of a* 
// sub_ab : the number of subsequences of a*b*
// sub_abc : the number of subsequences of a*b*c*

int countSubSeq(string &s) {
    int a = 0, ab = 0, abc = 0;
    
    for(int i = 0; s[i]; i++) {
        char ch = s[i];
        if(ch == 'a') 
            a = 2 * a + 1;
        else if(ch == 'b') 
            ab = 2 * ab + a;
        else 
            // ch == 'c'
            abc = 2 * abc + ab;
    }
    return abc;
}

int main() {
    
    string s;
    cin >> s;
    
    cout << countSubSeq(s);
    
    return 0;
}