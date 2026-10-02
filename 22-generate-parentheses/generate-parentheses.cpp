class Solution {
public:
    void dfs(int open,int close, string s, vector<string>&res, int n){
        if(open == close && open+close==2*n){
            res.push_back(s);
            return;
        }

        if(open<n){
            dfs(open+1,close,s+"(",res,n);
        }

        if(close<open){
            dfs(open,close+1,s+")",res,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,"",res,n);
        return res;
    }
};
