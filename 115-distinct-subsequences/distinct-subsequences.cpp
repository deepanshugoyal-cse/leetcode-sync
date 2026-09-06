class Solution {
public:

    int dp[1000][1000];

    int solve(string s, string t, int i, int j){
        int m=s.size();
        int n=t.size();

        if(j==n){
            return 1;
        }
        if(i==m) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]= solve(s,t,i+1,j) +solve(s,t,i+1,j+1);
        }
        else{
            return dp[i][j]= solve(s,t,i+1,j);
        }
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};