class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());

        int groupnum=0;
        unordered_map<int,int>numtogroup;
        numtogroup[v[0]]=groupnum;

        unordered_map<int,list<int>>grouptolist;
        grouptolist[groupnum].push_back(v[0]);

        for(int i=1; i<n; i++){
            if((v[i]-v[i-1])>limit){
                groupnum++;
            }
            numtogroup[v[i]]=groupnum;
            grouptolist[groupnum].push_back(v[i]);

        }

        vector<int>res(n);
        for(int i=0; i<n; i++){
            int num=nums[i];
            int group=numtogroup[num];
            res[i]=*grouptolist[group].begin();
            grouptolist[group].pop_front();
        }

        return res;

    }
};