class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> freq;
        set<int>seen;
        set<int>punished;
        int count = 0;
        for(auto c :word){
            int asci = int(c);
            if(asci>64 && asci<91){
                if(seen.contains(asci))continue;
                seen.insert(asci);
                if(freq.count(asci+32)==0)continue;
                count+=1;
               }
            else{
                if(seen.contains(asci-32)){
                    if(freq.count(asci)==0 && !punished.contains(asci))count++;
                    punished.insert(asci);}
                else{

                    if(freq.count(asci)==0)freq[asci]=0;
                    freq[asci]++;}
            }
        }
        int ans = count-punished.size();
        if(ans<0)return 0;
        return ans;
    }
};