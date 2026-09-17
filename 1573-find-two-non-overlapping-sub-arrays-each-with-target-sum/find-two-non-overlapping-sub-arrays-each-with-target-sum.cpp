class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n= arr.size();
        int i=0; int j=0; 
        int currsum=0;
        int res=INT_MAX;
        vector<int>minlen(n,INT_MAX);
        int bestminlen=INT_MAX;
        while(j<n){
            currsum+=arr[j];
            while(currsum>tar && i<j){
                currsum-=arr[i++];
            }
            if(currsum==tar){
                int len=j-i+1;
                if(i>0 && minlen[i-1]!=INT_MAX){
                    res=min(res,len+minlen[i-1]);
                }
                bestminlen=min(len,bestminlen);
            }
            minlen[j]=bestminlen;
            j++;
        }
        return res==INT_MAX?-1:res;
    }
};