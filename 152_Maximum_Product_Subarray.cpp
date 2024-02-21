#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums){
    int n = nums.size();
    int product = 1;
    int mx1 = -INT_MAX;
    int mx2 = -INT_MAX;
    int mx;
    for (int i = 0; i < n;i++) {
         product *= nums[i];
        mx1 = max(product, mx1);
        if(product == 0) {
            product = 1;
        }
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        product *= nums[i];
        mx2 = max(product, mx2);
        if(product == 0) {
            product = 1;
        }
    }
        return max(mx1,mx2);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum = maxProduct(v);
    cout << sum << endl;
}
