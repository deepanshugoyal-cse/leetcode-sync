class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        int cnt=0;
        for(auto x:s){
            
            if(x=='('){
                cnt++;
            }
            if(x==')'){
                cnt--;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};