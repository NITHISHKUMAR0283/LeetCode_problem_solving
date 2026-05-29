class Solution {
public:
    int sums (int ele){
        int sum = 0;
        while(ele>0){
            sum+=ele%10;
            ele/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto ele :nums){
            int sum_ele = sums(ele);
            mini = min(mini,sum_ele);
        }
        return mini;
    }
};