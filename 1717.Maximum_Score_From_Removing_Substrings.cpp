class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x < y) {
            swap(x,y);
            reverse(s.begin(),s.end());
        }

        int a_count = 0, b_count = 0;
        int total_point = 0;

        for(int i = 0; i < s.size(); i++) {
            char current_char = s[i];

            if(current_char == 'a' ) {
                a_count++;
            }
            else if(current_char == 'b') {
               if(a_count > 0) {
                  total_point += x;
                  a_count--;
               }
               else {
                 b_count++;
               }
            }
            else {
                total_point += min(a_count,b_count) * y;
                a_count = 0;
                b_count = 0;
            }

         }
         total_point += min(a_count,b_count)*y;

         return total_point;
    }
};