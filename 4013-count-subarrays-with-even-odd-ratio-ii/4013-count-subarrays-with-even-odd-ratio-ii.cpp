class fenwick{
    private:
    vector<int>bit;
    int n;
    public:
    fenwick(int m){
        bit.assign(m+1,0);
        n=m;
    }
    void add(int value,int index){

        while(index<=n){
            bit[index]+=value;
            index += index & (-index);

        }
    }
    int query (int index){
        int count = 0;
        while(index>0){
            count+=bit[index];
            index -= index&(-index);
        }
        return count;
    }

};
class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long > prefix(n+1,0);
        long long sum = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]%2==0)sum+=b;
            else sum-=a;
            prefix[i+1]=sum;
        }

        vector<long long >  comp(prefix.begin(),prefix.end());
        sort(comp.begin(),comp.end());

        comp.erase(unique(comp.begin(),comp.end()),comp.end());
        fenwick fn(comp.size());
        
        long long ans=0;
        for(int i = 0;i<=n;i++){
            int  rank = lower_bound(comp.begin(),comp.end(),prefix[i])-comp.begin()+1;
            

            int smaller = fn.query(rank-1);

            ans += i-smaller;
            
            fn.add(1,rank);

        }
        return ans;


    }
};