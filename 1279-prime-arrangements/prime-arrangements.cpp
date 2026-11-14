class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt =0;
        for(int i=2; i<=n; i++){
            bool isprime=true;
            for(int j=2; j*j<=i; j++){
                if(i%j==0){
                    isprime = false;
                    break;
                }
            }
            if(isprime) cnt++;
        }

        int p=cnt;
        int np=n-cnt;
        long long res=1;
        int mod=1e9+7;
        while(p>0){
            res=res*p%mod;
            p--;
        }
        while(np>0){
            res=res*np%mod;
            np--;
        }
        
        int ans = res%mod;
        return ans;
    }
};