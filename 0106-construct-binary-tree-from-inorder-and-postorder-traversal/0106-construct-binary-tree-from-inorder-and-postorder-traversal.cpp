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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& index,
                    unordered_map<int, int>& mpp, int inorderStart,
                    int inorderEnd) 
    {
        if (index < 0 || inorderStart > inorderEnd)
            return NULL;

        int element = postorder[index];
        TreeNode* root = new TreeNode(element);
        index--;

        int pos = mpp[element]; 

        root->right = solve(postorder, inorder, index, mpp, pos + 1, inorderEnd);
        root->left = solve(postorder, inorder, index, mpp, inorderStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 

        int postorderIndex = n - 1;

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        return solve(postorder, inorder, postorderIndex, mpp, 0, n - 1);
    }
};