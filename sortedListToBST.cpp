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
    TreeNode* sortedListToBST(ListNode* head) {
       //BC
       if(head == NULL) return NULL;
       if(head->next == NULL){
        TreeNode* temp = new TreeNode(head->val);
        return temp;
       }
       //first find the middle element of a linked list
       ListNode *slow = head;
       ListNode *fast = head;
       ListNode *prev = NULL;
       while(fast!=NULL && fast->next!=NULL)
       {
          prev = slow;
          fast = fast->next->next;
          slow = slow->next;
       }
       prev->next = NULL;
       //now make a root
       TreeNode* root = new TreeNode(slow->val);
       root->left = sortedListToBST(head);
       root->right = sortedListToBST(slow->next); //not root->next

       return root;
    }
};
