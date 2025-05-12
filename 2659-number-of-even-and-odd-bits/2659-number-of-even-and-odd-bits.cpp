class Solution {
public:
    vector<int> evenOddBit(int n) {
        int prity = 0;
        int even = 0, odd = 0;
        while(n>0) {
            if(prity % 2 == 0) {
                 if(n&1 !=0 ) {
                    even++;
                 }
            }
            else {
                if(n&1 != 0)odd++;
            }

            n = n>>1;
            prity = 1-prity;
           
        }

        return {even,odd};
        
    }
};