class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        // Step 1: match target's prefix as far as possible using available chars
        int matched = 0;
        while (matched < n) {
            int c = target[matched] - 'a';
            if (count[c] == 0) break;
            count[c]--;
            matched++;
        }

        // Step 2: backtrack from the rightmost matched position, looking for
        // the first place we can put a character strictly greater than target[pos]
        for (int pos = min(matched, n - 1); pos >= 0; pos--) {
            if (pos < matched) count[target[pos] - 'a']++; // restore this char

            int t = target[pos] - 'a';
            int found = -1;
            for (int c = t + 1; c < 26; c++) {
                if (count[c] > 0) { found = c; break; }
            }

            if (found != -1) {
                count[found]--;
                string res = target.substr(0, pos);
                res += (char)('a' + found);
                for (int c = 0; c < 26; c++)
                    res += string(count[c], (char)('a' + c));
                return res;
            }
        }

        return ""; // no permutation of s is greater than target
    }
};