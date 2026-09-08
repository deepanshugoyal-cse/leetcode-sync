class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int i=0; int j=0;
        int cnt=0;
        unordered_map<int,int>m;
        while(j<n){
            m[fruits[j]]++;
            if(m.size()<=2){
                cnt=max(cnt,j-i+1);
            }
            else{
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};