#include <bits/stdc++.h>
using namespace std;

struct Items {
  int value;
  int weight;
};

bool compare(Items &a, Items &b) {
    return (a.value / (double)a.weight) > (b.value / (double)b.weight);
}

double fractionalKnapsack(int W, Items *items, int n) {
    // sort the items based on the ratio: value / weight
    sort(items, items + n, compare);
    
    double max_val = 0;
    int cur_w = 0;
    
    for(int i = 0; i < n; i++) {
        // accomodate the full weight of the item
        if(cur_w + items[i].weight <= W) {
            cur_w += items[i].weight;
            max_val += items[i].value;
        }
        else {
            // fraction of the weight
            int rem_w = W - cur_w;
            max_val += items[i].value * (rem_w / (double)items[i].weight);
            break;
        }
    }
    return max_val;
}

int main() {
    
    int n;
    cin >> n;
    
    Items items[n];
    // input the values
    for(int i = 0; i < n; i++)
        cin >> items[i].value;
    
    // input the weights
    for(int i = 0; i < n; i++)
        cin >> items[i].weight;
    
    int W;
    cin >> W;
    
    double result = fractionalKnapsack(W, items, n);
    if((int)result == result)
        cout << fixed << setprecision(1) << result;
    else
        cout << result;
    
    return 0;
}