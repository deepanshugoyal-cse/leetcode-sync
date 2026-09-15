class Solution {
public:
    int countoverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowoff, int coloff){
        int n=A.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int Bi=i+rowoff;
                int Bj=j+coloff;
                if(Bi<0 || Bi>=n || Bj<0 || Bj>=n) continue;

                if(A[i][j]==1 && B[Bi][Bj]==1) cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();

        int maxoverlap=0;
        for(int rowoff=-n+1; rowoff<n; rowoff++){
            for(int coloff=-n+1; coloff<n; coloff++){
                int count =countoverlaps(A,B,rowoff,coloff);
                maxoverlap=max(maxoverlap,count);
            }
        }
        return maxoverlap;
    }
};