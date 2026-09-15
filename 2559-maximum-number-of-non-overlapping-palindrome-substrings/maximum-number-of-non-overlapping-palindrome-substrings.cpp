class Solution {
public:
    bool palin(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int l = 0;
        int cnt = 0;

        while (l + k <= n) {

            // Check length k
            if (palin(s, l, l + k - 1)) {
                cnt++;
                l += k;
            }

            // Check length k + 1
            else if (l + k < n && palin(s, l, l + k)) {
                cnt++;
                l += k + 1;
            }

            // No palindrome starting here
            else {
                l++;
            }
        }

        return cnt;
    }
};