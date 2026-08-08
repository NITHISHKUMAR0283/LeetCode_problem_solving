class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int n = s.size();
        int start = 0;
        int end = 0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            start = i;
            end = i;
            while(end<n && s[end]!=' '){
                end++;
            }
            string word ="";
            word =  (s.substr(start,end-start));
            if(word=="")continue;
            words.push_back(word);
            i=end+1;
        }
        reverse(words.begin(),words.end());
        string ans ;
        for(int i = 0;i<words.size();i++){
            ans+=words[i];
            if(i==words.size()-1)continue;
            ans+=" ";
        }
        return ans;
    }
};