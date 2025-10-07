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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        int level = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty())
        {
            int size = dq.size();
            vector<int> res;
            for(int i=0;i<size;i++)
            {
                if(level%2 == 0) //even
                {
                    TreeNode* temp = dq.back();
                    dq.pop_back();
                    res.push_back(temp->val);
                    if(temp->left) dq.push_front(temp->left);
                    if(temp->right) dq.push_front(temp->right);
                }
                else //odd
                {
                    TreeNode* temp = dq.front();
                    dq.pop_front();
                    res.push_back(temp->val);
                    if(temp->right) dq.push_back(temp->right);
                    if(temp->left) dq.push_back(temp->left);
                }
            }
            level++;
            ans.push_back(res);
        }
        return ans;
    }
};
