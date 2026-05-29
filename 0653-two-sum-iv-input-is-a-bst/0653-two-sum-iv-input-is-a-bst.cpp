/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
    
        TreeNode* current = root;
        stack<TreeNode*>st;
        set<int>visited;
        while(current != NULL){
            int complement = k-current->val;
            visited.insert(current->val);
            if(current->val!=complement){
            if(visited.contains(complement))return true;}
            if(current->left !=NULL)st.push(current->left);
            if(current->right!=NULL)st.push(current->right);
            if(st.empty())break;
            current = st.top();
            st.pop();
        }
        return false;
    }
};