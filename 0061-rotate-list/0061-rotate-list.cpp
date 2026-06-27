/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * current = head;
        int len = 1;
        if(head==NULL){
            return head;
        }
        while(current->next!=NULL){
            current=current->next;
            len++;
        }
        current->next = head;
        ListNode * ans = head;
        k = k % len;
        int comp = len-1-k;
        while(comp>=0){
            comp--;
            
            current = current->next;
            ans=current->next;
        }
        current->next = NULL;

        return ans;
        
    }
};