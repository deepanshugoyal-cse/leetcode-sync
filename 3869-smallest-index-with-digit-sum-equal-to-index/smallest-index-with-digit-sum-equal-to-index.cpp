class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            string x=to_string(nums[i]);
            int sum=0;
            for(char s:x){
                sum+=s-'0';

            }
            if(sum==i) return i;

        }
        return -1;
    }
};