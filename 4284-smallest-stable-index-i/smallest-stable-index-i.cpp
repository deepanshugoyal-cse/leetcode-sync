class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mini(n),maxi(n);

        int mi=INT_MAX;
        int ma=INT_MIN;

        for(int i=0; i<n; i++){
            ma=max(ma,nums[i]);
            maxi[i]=ma;
        }
        for(int i=n-1; i>=0; i--){
            mi=min(mi,nums[i]);
            mini[i]=mi;
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(maxi[i]-mini[i]<=k){
                ans=min(ans,i);
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};