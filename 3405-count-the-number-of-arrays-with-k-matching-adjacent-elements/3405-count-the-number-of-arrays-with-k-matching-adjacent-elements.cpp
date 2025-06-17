const int mod=1e9+7;
int fact[100000]={0};
class Solution {
public:
    static void compute_fact(){
        if(fact[0]==1) return; // compute once for all testcases
        long long product=1;
        fact[0]=1;
        for(int i=1; i<100000; i++){
            product*=i;
            if (product>=mod) product%=mod;
            fact[i]=product;
        }
    }
    static inline long long modPow(long long x, unsigned exp, int Mod=mod){
        if (exp==0) return 1;
        int bits=31-countl_zero(exp);
        bitset<32> B(exp);
        long long ans=x;
        for(int b=bits-1; b>=0; b--){
            ans=(ans*ans%Mod)*(B[b]?x:1)%Mod;
        }
        return ans;
    }

    // Euclidean algo finds x, y, d such that ax+by = d where d=gcd(a, b)
    static inline int modInverse(int a, int b=mod) {//mod is prime d=1
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while (r1 != 0) {
            int q = r0/r1, rr = r1, xx = x1;
            r1 = r0-q * r1;
            x1 = x0-q * x1;
            r0 = rr;
            x0 = xx;
        }
        if (x0 < 0) x0+= b;
        return x0;
    }
    static long long comb(int n, int k){// use defintion for C(n, k)
        return 1LL*fact[n]*modInverse(fact[k])%mod*modInverse(fact[n-k])%mod;
    }
    static int countGoodArrays(int n, int m, int k) {
        compute_fact();
        return m*modPow(m-1, n-k-1)%mod*comb(n-1, k)%mod;
        
    }
};