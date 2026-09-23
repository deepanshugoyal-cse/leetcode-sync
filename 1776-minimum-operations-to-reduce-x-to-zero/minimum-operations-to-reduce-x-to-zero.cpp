class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();   
        int total=0;
        for(int val:nums){
            total+=val;
        }
        total-=x;
        if(total<0) return -1;
        int sum=0;int i=0; 
        int longest=-1;
        for(int j=0; j<n; j++){
            sum+=nums[j];
            while(sum>total && i<=j){
                sum-=nums[i];
                i++;
            }
            if(sum==total){
                longest=max(longest,j-i+1);
            }
            

        }
        if(longest==-1) return -1;
        return n-longest;
    }
};