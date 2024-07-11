#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
void CloSolveKori() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int prefix_sum[n + 1];
    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << prefix_sum[i] << " ";
    }
    cout << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(prefix_sum[i] % 2 != 0) {
            cnt++;
        }
        if((prefix_sum[n-1] - prefix_sum[i])%2 != 0) {
            cnt++;
        }
    }
   cout << cnt << endl;
   for (int i = 1; i < n; i++) {
      
      if(i!=n-1) {
        if(arr[i]%2){
            cout << "one"<< arr[i] << " ";
            cnt++;
        }
      }
      if(i>1) {
        if((arr[i-1] + arr[i])%2) {
            cout << "two" << arr[i - 1] + arr[i] << " ";
            cnt++;
        }
      }
      
   }
   cout << cnt << endl;
}
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//  int tc; cin>>tc;
//  while(tc--)
 CloSolveKori();
return 0;
}