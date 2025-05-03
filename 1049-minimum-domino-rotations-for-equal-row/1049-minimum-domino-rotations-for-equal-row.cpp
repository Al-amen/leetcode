class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int>v1 = tops;
        vector<int>v2 = bottoms;
        
        map<int,int>tm,bm;
         int tf = 0, tv = tops[0];
         int bf = 0, bv = bottoms[0];
        for(int i = 0; i < n; i++) {
            tm[tops[i]]++;
            bm[bottoms[i]]++;
            if(tm[tops[i]] > tf) {
                tf = tm[tops[i]];
                tv = tops[i];
            }
            if(bm[bottoms[i]] > bf) {
                bv = bottoms[i];
                bf = bm[bottoms[i]];
            }

        }
        //cout << tf << " " << bf << endl;
        if(tf > bf) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(v1[i] != tv) {
                    swap(v1[i],v2[i]);
                    cnt++;
                }
            }
            if(count(v1.begin(),v1.end(),tv) == n) {
                return cnt;
            }
            else {
                return -1;
            }
        }
        else {
            int cnt = 0;
          // cout << "bf";
            for(int i = 0; i < n; i++) {
                if(v2[i] != bv) {
                    swap(v1[i],v2[i]);
                    cnt++;
                }
            }
            if(count(v2.begin(),v2.end(),bv) == n) {
                return cnt;
            }
            else {
                return -1;
            }

        }

        return 0;

        
    }
};