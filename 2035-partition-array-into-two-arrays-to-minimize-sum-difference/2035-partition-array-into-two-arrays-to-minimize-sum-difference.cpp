class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        vector<vector<int>> dp_left ;
        vector<vector<int>> dp_right ;

        int n = nums.size();

        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right (nums.begin()+n/2,nums.end());

        explore(dp_left,left,0,0,0);
        explore(dp_right,right,0,0,0);
        
        int sum = 0;
        for(auto ele:nums)sum+=ele;

        int target = sum/2;

        int low = 0;
        int high = n/2;
        int diff = INT_MAX;
        for(auto &v : dp_right){
    sort(v.begin(), v.end());
}
        for(int r = 0;r<dp_left.size();r++){
            for(int c = 0;c<dp_left[r].size();c++){
                int leftsum = dp_left[r][c];
                low = 0, high = dp_right[n/2-r].size()-1;
                target = sum/2-leftsum;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(dp_right[n/2-r][mid]<=target){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                }}
                int l_s = INT_MIN;
                int l_dif = INT_MAX;
                if(low<dp_right[n/2-r].size()){
                    l_s= dp_left[r][c]+dp_right[n/2-r][low];
                    l_dif = abs(sum-2*l_s);
                }
                if(high>=0){
                    l_s= dp_left[r][c]+dp_right[n/2-r][high];
                    l_dif = min(l_dif,abs(sum-2*l_s));
                }
                diff  = min(diff,l_dif);
                 
            }
        }
        return diff;


    }
    void explore(vector<vector<int>> & dp,vector<int> & arr,int len,int index, int sum){
        
        while(dp.size()<=len)dp.push_back(vector<int>());
        if(index==arr.size() ){
            dp[len].push_back(sum);
            return ;}
        explore(dp,arr,len+1,index+1,sum+arr[index]);
        explore(dp,arr,len,index+1,sum);
    }
};