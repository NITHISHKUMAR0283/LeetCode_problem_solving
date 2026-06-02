class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int current = 0;
        int y = n;
        int i =0;
        vector<int> result(2*n,0);
        while(i<2*n){
            result[i++]=nums[current++];
            result[i++]=nums[y++];
        }
        return result;

    }
};