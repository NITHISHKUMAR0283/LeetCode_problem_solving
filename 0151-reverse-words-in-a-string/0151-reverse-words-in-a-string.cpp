class Solution {
public:
    string reverseWords(string s) {
        while(s[0]==' ')s.erase(0,1);
        reverse(s.begin(),s.end());        
        while(s[0]==' ')s.erase(0,1);
        int i = 0;
        int n = s.length();
        
        while(i<n){
            while(i<n && s[i]==' ')i++;            
            int c_s = i;            
            while(i<n && s[i]!=' ')i++;            
            int c_e = i;
            
            reverse(s.begin()+c_s , s.begin()+c_e);            
            i++;
            if(i>=n)break;
            int start = i;
            int len = 0;
            while(s[i]==' '){
                len++;
                i++;
                
            }
            if(len>0){
                s.erase(start,len);
                
            }
            
            n = s.length();
            i=start;
        }
        return s;
    }
};