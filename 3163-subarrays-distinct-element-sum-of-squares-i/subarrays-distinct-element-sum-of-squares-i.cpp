class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int i=0; int j=0;
        int n=nums.size();
        vector<int>dis;

        for(int i=0; i<n; i++){
            unordered_set<int>s;
            int cnt=0;
            for(int j=i; j<n; j++){
                if(s.find(nums[j])==s.end()){
                    s.insert(nums[j]);
                    cnt++;
                }
                dis.push_back(cnt);
            }
        }
        long long sum=0;
        for(int i=0; i<dis.size(); i++){
            int x=dis[i]*dis[i];
            sum+=x;
        }
        return (int)sum;
    }
};