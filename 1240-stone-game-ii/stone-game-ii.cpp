class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(vector<int>& piles, int person,int i, int m){
        if(i>=n) return 0;
        if(t[person][i][m]!=-1){
            return t[person][i][m];
        }
        int res= person==1?-1:INT_MAX;
        int stones=0;
        for(int x=1; x<=min(2*m,n-i); x++){
            stones+=piles[i+x-1];
            if(person==1){
                res= max(res,stones+solve(piles,0,i+x,max(m,x)));
            }
            else{
                res= min(res,solve(piles,1,i+x,max(m,x)));
            }
        }
        return t[person][i][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solve(piles,1,0,1);
    }
};