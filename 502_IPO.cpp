#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    int m = capital.size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({capital[i], profits[i]});

    }
    sort(vp.begin(), vp.end());
    priority_queue<int> mxProfite;
    int j = 0;
    for (int i = 0; i < k; i++) {
      while(j<n and vp[j].first <= w) {
          mxProfite.push(vp[j].second);
          j++;
      }
      if(mxProfite.empty())break;
      w += mxProfite.top();
      mxProfite.pop();
    }
    return w;

    //     int low = lower_bound(vp.begin(), vp.end(), w) - vp.begin();
    // cout << low << endl;
  }
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int k, w,n;
cin >> k >> w>>n;
vector<int> profits(n), capital(n);
for (int i = 0; i < n; i++) {
    cin >> profits[i];
}
for (int i = 0; i < n; i++) {
    cin >> capital[i];
}

 cout << findMaximizedCapital(k, w, profits, capital);
}