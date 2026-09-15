class Solution {
public:
    int mod=1e9+7;
    long long power( long long x,long long y){
        if(y==0) return 1;
        long long half = power(x,y/2);
        long long res=(half*half)%mod;
        if(y%2==1){
            res=(res*x)%mod;
        }
        return res;
    }
    int maxdepth(unordered_map<int,vector<int>>& adj, int node, int par){
        int depth=0;
        for(auto neigh:adj[node]){
            if(neigh==par) continue;
            depth =max(depth,1+maxdepth(adj,neigh,node));
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int d=maxdepth(adj,1,-1);
        return power(2,d-1);
    }
};