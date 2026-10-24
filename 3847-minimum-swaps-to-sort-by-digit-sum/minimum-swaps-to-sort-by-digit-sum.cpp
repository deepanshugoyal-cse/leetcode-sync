class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>sum;
        int n=nums.size();
        for(int x:nums){
            int a=0;
            while(x){
                a+=x%10;
                x/=10;
            }
            sum.push_back(a);
        }
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({sum[i],nums[i]});
        }
        sort(v.begin(),v.end());
        vector<int>tar;
        for(auto x:v){
            tar.push_back(x.second);
        }
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        int swaps=0;
        for(int  i=0; i<n; i++){
            if(tar[i]!=nums[i]){
                int j=m[tar[i]];
                m[nums[i]]=j;
                m[tar[i]]=i;
                swap(nums[i],nums[j]);
                swaps++;
            }
        }
        return swaps;

    }
};