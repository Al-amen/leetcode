#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {

    int n = nums.size();
    int l = 0, h = n - 1;

    while(l<=h) {
        int mid = (h + l) / 2;
        if(nums[mid] < nums[h]) {
            h = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return nums[h];
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

        cout << findMin(v) << endl;
}
