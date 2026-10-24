class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int i=0; int j=nums.size()-1;
        long long ans=0;
        for(int k=0; k<nums.size(); k++){
            if(nums[k]<0){
                nums[k]=-nums[k];
            }
        }
        sort(nums.begin(),nums.end());
        while(i<j){
            long long p=1LL*nums[j]*nums[j];
            long long s=1LL*nums[i]*nums[i];

            ans+=(p-s);
            i++; j--;
        }
        if(nums.size()%2==1){
            long long p=1LL*nums[j]*nums[j];
            ans+=p;
        }
        return ans;
    }
};