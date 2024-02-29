#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 vector<int> sortedSquares(vector<int>& nums) {
     int n = nums.size();
     int l = 0, r = n - 1;
     vector<int> v(n);
     for (int i = n-1; i >=0 ; i--) {
        if(abs(nums[l]) > abs(nums[r])) {
            
            
            v[i] = nums[l] * nums[l];
            l++;
        }
        else {
            v[i] = nums[r] * nums[r];
            r--;
        }
        
     }
     return v;
 }




int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  vector<int> x = sortedSquares(v);

  for (int i = 0; i < n; i++) {
      cout << x[i] << " ";
  }

      return 0;
}
