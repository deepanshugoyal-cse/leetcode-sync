class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> seen;
        int n = digits.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (i != j && j != k && i != k && digits[i] && digits[k] % 2 == 0)
                        seen.insert(digits[i]*100 + digits[j]*10 + digits[k]);
        return seen.size();
    }
};