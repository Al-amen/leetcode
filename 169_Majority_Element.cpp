#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
  int majorityElement(vector<int>& nums) {
      int n = nums.size();
      int vote = 0;
      int candiate = -1;

      for (int i = 0; i < n; i++) {
        if(vote == 0) {
            candiate = nums[i];
            vote = 1;
        }
        else if(nums[i] == candiate) {
            vote++;
        }
        else {
            vote--;
        }
      }

      return candiate;
 }
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << majorityElement(v) << endl;

    return 0;
}