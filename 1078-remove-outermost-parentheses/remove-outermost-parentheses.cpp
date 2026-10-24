class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int i=0,a=0,b=0;

        while(i<s.size()){
            if(s[i]=='(') a++;
            if(s[i]==')') b++;
            if(a==b){
                i++;
                a=0; b=0;
                continue;
            }
            else if(s[i]=='(' && a>1) ans+=s[i];
            else if (s[i]==')') ans+=s[i];
            
            i++;
        }
        return ans;
    }
};