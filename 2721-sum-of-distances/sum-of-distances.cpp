class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();

        vector<long long>arr(n);
        unordered_map<int,long long >sum;
        unordered_map<int,long long >count;

       
        for(int i=0; i<n; i++){
            long long freq=count[nums[i]];
            long long s=sum[nums[i]];

            arr[i]+=freq*i-s;

            count[nums[i]]+=1;
            sum[nums[i]]+=i;
        }

        sum.clear();
        count.clear();
        for(int i=n-1; i>=0; i--){
            long long freq=count[nums[i]];
            long long s=sum[nums[i]];

            arr[i]+= s- freq*i;

            count[nums[i]]+=1;
            sum[nums[i]]+=i;
        }
        return arr;
    }
};