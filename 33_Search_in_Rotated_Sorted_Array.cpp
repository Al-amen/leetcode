#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, h = n-1;
        while(l<= h) {
            int mid = (l+h)/2;
            //cout << mid << " ";
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] >= nums[l]) {
                if(target >= nums[l] and target < nums[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
                
            }
            else {

                if(target > nums[mid] and target <= nums[h]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
               
            }
        }
        return -1;
        
    }

int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, target;
cin >> n >> target;
vector<int> v(n);
for (int i = 0; i < n; i++) {
    cin >> v[i];
}

cout << search(v, target) << endl;

return 0;
}