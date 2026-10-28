class Solution {
public:
    int n, m;
    int res=1e9;
    vector<vector<vector<bool>>>vis;

    void solve(int i, int j, vector<vector<int>>& grid, int count) {
        if (i == n || j == m) {
            return;
        }
        
        if (i == 0 && j == 0)
            count = grid[0][0];
        else
            count = count ^ grid[i][j];
        if(vis[i][j][count])return;
        vis[i][j][count]=true;
        if(i==n-1 && j==m-1){
            res=min(res,count);
            
        }    
        solve(i + 1, j, grid, count);
        solve(i, j + 1, grid, count);
    }
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count=0;
        vis.assign(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
        solve(0, 0, grid, count);
        return res;
    }
};