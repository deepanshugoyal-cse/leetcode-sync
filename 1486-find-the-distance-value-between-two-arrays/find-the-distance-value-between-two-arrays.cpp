class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        int m = arr1.size();
        vector<int> close(m);
        for (int i = 0; i < m; i++) {
            int l = 0, r = n;
            int x = arr1[i];
            while (l < r) {
                int mid=l+(r-l)/2;
                if (arr2[mid]< x) {
                    l = mid + 1;
                } else
                    r = mid;
            }
            int best = INT_MAX;                  // changed: check both neighbors
            if (l < n) best = arr2[l] - x;
            if (l > 0) best = min(best, x - arr2[l - 1]);
            close[i] = best;

        }
        int cnt=0;
        for(int k=0; k<m; k++){
            if(close[k]>d){
                cnt++;
            }
        }
        return cnt;

    }
};