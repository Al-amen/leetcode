class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        int tt = 0;
        for(int i = 0; i < n; i++) {
    	int x = (s[i]-97)+1;
    	if(x<=9){
    		tt += x;
    	}
    	else {
    		tt += x%10;
    		x = x/10;
    		tt += x;
    	}
        
    }
    k--;
    	int a = tt;
    
    while(k--) {
    	int x = 0;
    	while(a) {
    		x += a%10;
    		a /= 10;
    		
    	}
    	a = x;
    	
    }
     return a;
    }
    
};