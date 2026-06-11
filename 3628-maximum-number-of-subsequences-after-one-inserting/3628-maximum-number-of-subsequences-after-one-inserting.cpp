class Solution {
public:
    long long numOfSubsequences(string s) {
        long long n = s.length();
        vector<long long> dpl(1+n,0);
        long long count = 0;
        for(long long i = 0;i<n;i++){
            if(s[i]=='L')dpl[i+1]=1;
            dpl[i+1]+=dpl[i];
        }
        count = 0;
        
        vector<long long> dpt(1+n,0);
        for(long long i = n-1;i>=0;i--){
            if(s[i]=='T')dpt[i]=1;
            dpt[i]+=dpt[i+1];
        }
        long long ansl=0;
        long long ansc = 0;
        long long anst = 0;
        long long occ = 0;
        long long best = 0;
        for(long long i = 0;i<n;i++){
            if(s[i]=='C'){
                occ++;
                ansl += (dpl[i]+1)*dpt[i+1];
                anst  += dpl[i]*(dpt[i+1]+1);
                ansc += dpl[i]*dpt[i+1];
                                }
                else{
                best= max(best,dpl[i]*dpt[i]);
                }
        }
        ansc +=best;
        return max(ansl,max(ansc,anst));
    }
};