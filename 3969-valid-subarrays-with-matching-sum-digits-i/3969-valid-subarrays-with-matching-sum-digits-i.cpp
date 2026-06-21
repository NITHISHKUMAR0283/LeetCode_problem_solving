class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        set<long long > visited;
        long long  sum = 0;
        int   n = nums.size();
        int  count=0;
        visited.insert(0);

        for(int i = 0;i<n;i++){
            sum+=nums[i];
            
            for(auto ele : visited){
                long long possible = sum-ele;
                int len =(int)((possible==0)?1: log10(possible));
                if(((possible%10) ==x) &&( possible/(long long )pow(10,len) )==x){
                    count++;
                }
            }
            
            visited.insert(sum);
        }
        return count;
    }
};