class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        string result;

        for(auto x:s){
            if(x=='('){
                st.push(result.size());
            }
            else if(x==')'){
                int start=st.top();
                st.pop();
                reverse(result.begin()+start,result.end());
            }
            else {
                result+=x;
            }
        }
        return result;
    }
};