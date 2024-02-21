#include<bits/stdc++.h>
using namespace std;

 bool checkSubarraySum(vector<int>& nums, int k) {
     int n = nums.size();
    vector<int> sum(n + 1);
    
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + nums[i -1];
    }
    
     unordered_set<int> set;
    
    for(int i = 2; i <= n; i++){
        set.insert(sum[i - 2] % k);
        if(set.find(sum[i] % k) != set.end()) return true;
    }
    return false;
 }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool ck = checkSubarraySum(v,k);
    if(ck) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}
