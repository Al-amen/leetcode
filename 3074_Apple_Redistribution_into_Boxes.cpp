#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

     int n = apple.size();
     int m = capacity.size();
     int x = accumulate(apple.begin(), apple.end(),0);
     //cout << x << endl;
     sort(capacity.begin(), capacity.end());
     int sum = 0;
     int cnt = 1;
     for (int i = m - 1; i >= 0; i--) {
        if(sum + capacity[i] < x) {
            cnt++;
            sum += capacity[i];
            
        }
        else {
           break;
            
        }
     }
     return cnt;
}
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> apple = {1, 3, 2};
vector<int> capacity = {4, 1, 5, 2};

cout << minimumBoxes(apple,capacity);

return 0;
}