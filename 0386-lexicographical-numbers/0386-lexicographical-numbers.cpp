class Solution {

public:
    void generateLexicalNumber(int currNumber,int limit,vector<int> & result) {
        if(currNumber > limit) return;
        result.push_back(currNumber);
        for(int i = 0; i <= 9; i++) {
            int x = currNumber * 10 + i;
            if(x <= limit) {
                generateLexicalNumber(x,limit,result);
            }
            else {
                break;
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> lexNumber;
        for(int i = 1; i <= 9; i++) {
            generateLexicalNumber(i,n,lexNumber);
        }
        return lexNumber;
        
    }
};