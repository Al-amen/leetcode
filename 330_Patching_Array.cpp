#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int minPatches(vector<int>& nums, int n) {
        int count = 0;
        int i = 0;
        long reach = 0;
        while(reach<n) {

            if (i>=nums.size()) {
                
                reach += reach+1;
                count++;
            }
            else if(i <nums.size() && nums[i] <= (reach+1)) {
                reach += nums[i];
                i++;
            } else {
                
                reach += reach+1;
                count++;

            }

        }
        return count;
    }
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
  vector<int> v = {1, 3};
  cout << minPatches(v, 6);

  return 0;
}