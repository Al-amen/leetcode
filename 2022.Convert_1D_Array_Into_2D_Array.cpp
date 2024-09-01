class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vec( m , vector<int> (n));
        int x = 0;
        int sz = original.size();
        if (m*n != sz){
            return  vector<vector<int>>( 0 , vector<int> (0));
        }
        for(int i = 0; i <m; i++) {
            
                     for(int j = 0; j < n; j++) {
               
                    vec[i][j] = original[x];
                    x++;
                
                     
         }
           
            
        }
        
        
            return vec;
        
    }
};