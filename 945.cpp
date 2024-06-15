#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>v;
        int moves = 0;
        int mx = -1;
        int mn = 1e6 + 7;

        mx = *max_element(nums.begin(), nums.end());
        vector<int> freqencyCount(n + mx + 1,0);

        for(auto it : nums) {
            freqencyCount[it]++;
        }

        for (int i = 0; i < freqencyCount.size(); i++) {
            if(freqencyCount[i] <= 1) {
                continue;
            }
            int duplicates = freqencyCount[i] - 1;
            freqencyCount[i + 1] += duplicates;
           freqencyCount[i] = 1;
           moves += duplicates;
        }

            return moves;
        
    }


int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> vs = {0 ,2 ,0};
cout << minIncrementForUnique(vs);
}