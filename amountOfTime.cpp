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
    void build(TreeNode* root,unordered_map<int,vector<int>> &graph)
    {
        if(root == NULL)
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
    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL)
        {
            return 0;
        }
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;

        build(root,graph);

        queue<int> q;
        q.push(start);
        visited[start] = true;

        int time = -1;// start from -1 because the 0th level is the starting node

        while(!q.empty())
        {
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                int val = q.front();
                q.pop();
                for(int node:graph[val])
                {
                    if(!visited[node])
                    {
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
            time++;
        }

        return time;
    }
};
