class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n);

        int sodd = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (nums1[j] % 2 == 1)
                sodd = min(nums1[j], sodd);
        }

        if (sodd == INT_MAX)
            return true; // no odd numbers at all -> already uniform (even)

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                nums2[i] = nums1[i];
            } else {
                if (nums1[i] - sodd >= 1) {
                    nums2[i] = nums1[i] - sodd;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};