/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void build(TreeNode* root, unordered_map<int,vector<int>>& graph)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left)
        {
           graph[root->val].push_back(root->left->val);
           graph[root->left->val].push_back(root->val);
           build(root->left,graph);
        }
        if(root->right)
        {
           graph[root->val].push_back(root->right->val);
           graph[root->right->val].push_back(root->val);
           build(root->right,graph);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
        {
            return {target->val}; 
        }
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;
        vector<int> res;
        queue<int> q;
        int level = 0;

        build(root,graph); //we see target as root in this graph and level order traversal

        q.push(target->val);
        while(!q.empty())
        {
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                int val = q.front();
                q.pop();
                visited[val] = true;
                for(int node:graph[val])
                {
                    if(!visited[node])
                    {
                        q.push(node);
                    }
                }
            }
            level++;
            if(level==k)
            {
                while(!q.empty())
                {
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }

        return res;
    }
};
