class Solution {
public:
    int longestOnes(vector<int>& nums, int m) {
        int cnt=0;
        int n=nums.size();
        int i=0,j=0;
        int k=m;
        while(j<n ){
            if(nums[j]==1){
                j++;
            }
            else if(nums[j]==0 && k>0){
                j++;
                k--;
            }
            else{
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            cnt=max(cnt,j-i);
        }
        return cnt;
    }
};