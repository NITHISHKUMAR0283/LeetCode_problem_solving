class Solution {
public:
    string longestPalindrome(string s) {
        int c = 0, r = 0;
        int max_i = 0;
        int max_value = INT_MIN;
        string preprocessed = "#";
        for(char c :s){
            preprocessed+=c;
            preprocessed+='#';
        }
        int lenp = preprocessed.length();        
        vector<int> manacher(lenp,0);
        for(int i = 0;i<lenp;i++){
            int mirror = c-(i-c);
            if(i<r)manacher[i]=min(r-i,manacher[mirror]);
            while(i+manacher[i]+1<lenp && i-manacher[i]-1>=0 && preprocessed[i+manacher[i]+1]==preprocessed[i-manacher[i]-1]){
                manacher[i]++;
            }
            if(manacher[i]+i>r){
                c= i;
                r = manacher[i]+c;
            }       
            if(manacher[i]>max_value){
                max_value=manacher[i];
                max_i=i;
            } }
        
        int start = (max_i-max_value)/2;
        return s.substr(start,max_value);
    }
};