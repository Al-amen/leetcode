class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int cnt1 = 0, cnt2 = 0;
        int main = 0;
        for(int i = 0; i < n; i++) {
            if(logs[i] != "./" && logs[i] != "../") {
                    main++;
            }
            if(logs[i] == "../") {
                if(main > 0) {
                    main--;
                }
            }
        }
       
        return main;

        
    }
};
