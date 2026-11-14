class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int res1=1;
        if(n==1) return 1;
        int i=0,j=1;
        while(j<n){
            if(nums[j]>nums[j-1]){
                res1=max(res1,j-i+1);
                j++;
            }
            else {i++;j=i+1;}
        }

       
        i=0,j=1;
        while(j<n){
            if(nums[j]<nums[j-1]){
                res1=max(res1,j-i+1);
                j++;
            }
            else {i++;j=i+1;}
        }

        return res1;
    }
};