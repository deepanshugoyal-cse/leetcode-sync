class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int asc=0;
        int dsc=0;
        for(int i=1; i<n; i++){
            if(nums[i]==(nums[i-1]+1)%n){
                asc++;
            }
            if(nums[i-1]==(nums[i]+1)%n){
                dsc++;
            }
        }
        if(asc==n-1 && nums[0]==0) return 0;
        if(asc==n-1){
            int left=n-nums[0];
            int right= 1+nums.back()+1+1;

            return min(left,right);
        }
        if(dsc==n-1){
            int left = n-nums.back()+1;
            int right= (nums.front()+1)%n +1;

            return min(left,right);
        }

        return -1;
        
    }
};