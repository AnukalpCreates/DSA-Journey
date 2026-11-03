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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        // If left and right heights are equal, it's a full binary tree.
        // We can directly find the number of nodes using 2^height - 1.
        if (lh == rh) return (1 << lh) - 1;
        
        // Otherwise, recursively calculate for left and right subtrees + 1 (for the root)
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int findHeightLeft(TreeNode* node) {
        int hgt = 0;
        while (node) {
            hgt++;
            node = node->left;
        }
        return hgt;
    }
    
    int findHeightRight(TreeNode* node) {
        int hgt = 0;
        while (node) {
            hgt++;
            node = node->right;
        }
        return hgt;
    }
};