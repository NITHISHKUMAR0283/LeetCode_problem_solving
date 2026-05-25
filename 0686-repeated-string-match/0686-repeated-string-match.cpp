class Solution {
public:
    vector<int> kmp(string a ,string b){
        int m = b.length();

        vector<int> lcs(m,0);
        
        int i=1;
        int len =0;

        while(i<m){
            if(i<m && b[i]==b[len]){
                len++;
                lcs[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lcs[len-1];
                }
                else {
                    lcs[i]=0;
                    i++;
                }
            }
        }
        return lcs;
    }
    bool substring_kmp(string a , string b){
        int n = a.length();
        int m = b.length();

        vector<int> lcs = kmp(a,b);
        int i =0;
        int j = 0;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            if(j==m)return true;
            else if(i<n && a[i]!=b[j]){
                if(j==0)i++;
                else j=lcs[j-1];
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n =a.length();
        int m = b.length();
        string temp = "";
        int count = 0;
        while(temp.size()<m){
            temp+=a;
            count ++;
        }
        if(substring_kmp(temp,b))return count;
        else if (substring_kmp(temp+a,b))return count+1;
        return -1;
    }
};