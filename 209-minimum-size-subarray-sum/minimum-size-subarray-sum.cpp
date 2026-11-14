class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        int sum =0;
        int i=0,j=0;
        while(i<n && j<n){
            sum+=nums[j];
            while(sum>=tar){
                res=min(j-i+1,res);
                sum-=nums[i++];
            }
            j++;
            
        }
        return res==INT_MAX?0:res;
    }
};