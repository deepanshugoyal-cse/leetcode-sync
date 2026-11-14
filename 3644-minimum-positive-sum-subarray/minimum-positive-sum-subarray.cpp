class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res=INT_MAX;
        for(int i=l; i<=r; i++){
            int j=0; int k=0;
            while(k<nums.size()&& k<j+i){
                int sum=0;
                while(k!=j+i && k<nums.size()){
                    sum+=nums[k];
                    k++;
                }
                if(k==j+i && sum>0) res=min(res,sum);
                j++; k=j;
            }
            
        }
        return res==INT_MAX?-1:res;
    }
};