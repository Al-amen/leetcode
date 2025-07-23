class Solution {
public:
      int modify(string pattern,string& s,const int& points){
        int n = s.size();
        if(n<2)  return 0;

        string new_s;
        int tot = 0;
        for(int i=0;i<n;++i){
            if(new_s.size() and new_s.back()==pattern[0] and s[i]==pattern[1]){
                new_s.pop_back();
                tot += points;
            }else{
                new_s.push_back(s[i]);
            }
        }
        s = new_s;
        return tot;
    }
    int maximumGain(string s, int x, int y) {
        string copy_s = s;
        int points = 0;
        if(x>y){
            points += modify("ab",copy_s,x);
            points += modify("ba",copy_s,y);
        }else{
            points += modify("ba",copy_s,y);
            points += modify("ab",copy_s,x);
        }
        return points;
    }
};