class Solution {
public:
    int m,n;
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(i>=m||j>=n||i<0||j<0){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        bool a=dfs(i+1,j,grid);
        bool b=dfs(i,j+1,grid);
        bool c=dfs(i-1,j,grid);
        bool d=dfs(i,j-1,grid);
        return  a && b && c  && d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)) cnt++;
                }
            }
        }
        return cnt;
    }
};