class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0;
        int maxm=*max_element(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            cnt+=(maxm-nums[i]);
        }
        return cnt;
    }
};