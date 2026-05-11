class Solution {
public:
    struct TreeNode{
        TreeNode* children [2];
        TreeNode(){
        children[0]=NULL;
        children[1]=NULL;
        }
    };

    void insert(int ele,TreeNode * head){
        bitset<31> binary (ele);
        TreeNode * current = head;
        for(int i = 30;i>=0;i--){
            int bin = binary[i];
            if(current->children[bin]==NULL){
                current->children[bin]=new TreeNode();
            }
            current  = current->children[bin];
        }
    }
    int xor1 ( int ele , TreeNode * head){
        bitset <31> binary(ele);
        int sum = 0;
        int pow11 = 31;
        TreeNode* current = head;
        for(int i = 30;i>=0;i--){
            int bit = 1-binary[i];
            if(current->children[bit]==NULL){
                current = current->children[1-bit];
                continue;
            }
            sum|=(1<<i);
            current = current->children[bit];
        }
        return sum;
    }
    int findMaximumXOR(vector<int>& nums) {
        TreeNode * head =new TreeNode();
        for(int ele :nums){
            insert(ele,head);
        }
        int maxi = 0;
        for(int ele : nums){
            maxi  = max(maxi , xor1(ele,head));
        }
        return maxi;
    }
};