class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int cnt=1;
        int ans=1;
        for(int i=1; i<n; i++){
            if(s[i]==(s[i-1]+1)){
                cnt++;
            }
            else cnt=1;
            ans=max(cnt,ans);
        }
        return ans;
       
    }
};