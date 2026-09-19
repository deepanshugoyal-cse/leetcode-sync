class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001];
    int numberOfSets(int n, int K) {
        for(int i=0; i<n; i++){
            dp[0][i]=1;
        }

        for(int k=1; k<=K; k++){
            vector<int>prevsum(n+1,0);
            for(int x=n-1; x>=0; x--){
                prevsum[x]=(prevsum[x+1]+dp[k-1][x])%mod;
            }
            for(int i=n-1; i>=0; i--){
                int take=prevsum[i+1];
                int skip = dp[k][i+1]%mod;
                dp[k][i]=(take+skip)%mod;
            }
        }
        return dp[K][0];
    }
};