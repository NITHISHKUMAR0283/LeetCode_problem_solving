class Solution {
public:
    int manacher(string s){
        int len = s.length();
        int c =0;
        int r =0;
        vector<int> pali(len,0);
        int count =  0;
        for(int i =0;i<len;i++){
            int mirror = 2*c-i;
            if(i<r) pali[i]=min(r-i,pali[mirror]);
            while(i-pali[i]-1>=0 && i+pali[i]+1<len && s[i-pali[i]-1]==s[i+pali[i]+1]){
                pali[i]++;
            }
            if(i+pali[i]>r){
                c=i;
                r=pali[i]+c;
            }
            count+=(pali[i]+1)/2;
        }
        return count;
    }   
    int countSubstrings(string s) {
        string preprocessed = "#";
        for(char c:s){
            preprocessed+=c;
            preprocessed+='#';
        }
        int count = manacher (preprocessed);
        return count;
    }
};