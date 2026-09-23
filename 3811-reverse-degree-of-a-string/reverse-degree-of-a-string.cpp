class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int n=s.size();
        for(int i=1; i<=n; i++){
            int deg;
            deg=i*(26-s[i-1]+'a');
            sum+=deg;
        }
        return sum;
    }
};