class Solution {
public:
    int base = 1000000;
    int rabin_karp(string text , string pattern){
        if(text == "" or pattern=="")return -1;
        int n = text.length();
        int m = pattern.length();

        int power = 1;
        for(int i = 0;i<m;i++){
            power=(power*31)%base;
        }
        int hash = 0;
        for(int i=0;i<m;i++){
            hash = (hash*31+pattern[i])%base;
        }
        int l = 0;
        int curr_hash =0;
        for(int r = 0;r<n;r++){            
            curr_hash = (curr_hash*31+text[r])%base;
            if(r-l+1>m){
                curr_hash = ((curr_hash-text[l]*power)%base+base)%base;
                l++;
            }           
            int length = r-l+1;
            if(length<m)continue;
            if(curr_hash == hash){
                if(text.substr(l,m)==pattern){
                    return l;
                }
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        int m = b.length();
        string temp = "";
        int count = 0;
        while(temp.length()<m){
            temp += a;
            count++;
        }
        if(rabin_karp(temp,b)!=-1)return count;
        if(rabin_karp(temp+a,b)!=-1)return count+1;
        return -1;
    }
};