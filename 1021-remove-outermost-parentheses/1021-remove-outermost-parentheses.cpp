class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        int n = s.size();
        int start = 0;
        int len = 0;
        int i =0;
        string res = "";
        while(i<n){
            if(s[i]=='(')balance++;
            else balance--;
            len++;
            if(balance ==0){
                res.append(s.substr(start+1,len-2));
                start=i+1;
                len=0;
            }
            i++;
        }
        return res;
    }

};