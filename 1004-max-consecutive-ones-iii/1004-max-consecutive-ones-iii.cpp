class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();

        int left_i = 0;
        int right_i = 0;

        int count_z = 0;
        int ans = 0;
        while(right_i<n || count_z>k){
            if(count_z>k){
                if(nums[left_i]==0)count_z--;
                left_i++;                             
                
            }           
            else{                              
                if(nums[right_i]==0)count_z++;                
                right_i++;     
                cout<<left_i<<" "<<right_i<<endl;           
                if(count_z<=k){
                ans = max(ans,right_i-left_i);  
            }}
            
        }
        return ans;


    }
};