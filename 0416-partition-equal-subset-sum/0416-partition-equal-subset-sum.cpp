class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        vector<bool> present (sum+1,false);
        int n = arr.size();
        
        present[0]=true;
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            //assuming using the current as the last step can we reach the sum of prev
            for(int res = sum;res>-1;res--){
                int prev = res-curr;
                if(prev<0)continue;
                if(present[prev]==true){
                    present[res]=true;
                }
            }
        }
        return present[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate (nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        int target = sum/2;
        return isSubsetSum(nums,target);



    }

};