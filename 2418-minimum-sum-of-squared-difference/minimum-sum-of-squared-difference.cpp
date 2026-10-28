class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int k=k1+k2;
        int n=nums1.size();

        vector<int>countdiff(1e5+1,0);

        for(int i=0; i<n; i++){
            int d=abs(nums1[i]-nums2[i]);
            countdiff[d]++;
        }  
        for(int i=1e5; i>0 && k>0 ; i--){
            int countops= min(countdiff[i],k);
            countdiff[i]-=countops;
            countdiff[i-1]+=countops;
            k-=countops;
        }

        long long res=0;
        for(long long i=1; i<=1e5; i++){
            res+=(i*i*countdiff[i]);
        }
        return res;
    }
};