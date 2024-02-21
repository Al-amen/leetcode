#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int sum = 0;
    int ans = -INT_MAX;
    for (int i = 0; i < n;i++) {
        sum += nums[i];
        ans = max(sum, ans);
        if(sum < 0) {
            sum = 0;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum = maxSubArray(v);
    cout << sum << endl;
}
