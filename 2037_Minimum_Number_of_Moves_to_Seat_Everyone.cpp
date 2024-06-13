#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define endl   '\n' 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());

        int n = students.size();
        int move = 0;
        for(int i = 0; i<n; i++) {
            move += abs(seats[i]-students[i]);
        }

        return move;
        
    }
};


int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
return 0;
}