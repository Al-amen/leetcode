class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int lsum = 0, rsum = 0, rind = cardPoints.size()-1;
        int mxSum = 0;

        for(int i = 0; i < k; i++) lsum += cardPoints[i];
        mxSum = lsum;
        for(int i = k-1; i>= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rind];
            rind--;
            mxSum = max(mxSum , lsum + rsum);
        }
        return mxSum;

        
    }
};