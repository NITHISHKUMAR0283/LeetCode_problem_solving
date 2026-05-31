class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int neg = 1;
        int pos = 0;
        vector<int> array (n);
        for(int ele:nums){
            if(ele>=0){
                array[pos]=ele;
                pos+=2;
            }
            else{
                array[neg]=ele;
                neg+=2;
            }
        }
        return array;}
};