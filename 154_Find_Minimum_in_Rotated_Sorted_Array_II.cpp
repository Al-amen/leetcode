#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, h = n-1;

    while(l<h) {
        int mid = (l+h)/2;
        if(nums[mid] < nums[h]){
            h = mid;
        }
        else if(nums[mid]>nums[h]) {
            l = mid + 1;
        }
        else {
            h--;
        }
        
    }
    return nums[h];
  }
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout <<  findMin(v) << endl;

    return 0;
}