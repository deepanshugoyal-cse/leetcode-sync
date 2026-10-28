
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> s(m, string(n, '#'));

        for (int i = 0; i < m; i++) {
            s[i][n-1] = '.';
        }

        for (int j = 0; j < n; j++) {
            s[0][j] = '.';
        }

        return s;
    }
};

