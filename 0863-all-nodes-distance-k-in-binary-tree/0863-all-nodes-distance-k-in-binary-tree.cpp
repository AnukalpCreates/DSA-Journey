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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // child -> parent
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        // Traverse radially outward from target until reaching distance k
        while (!q.empty()) {
            int size = q.size();
            if (curr_level == k) break;
            curr_level++;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // 1. Move left
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // 2. Move right
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // 3. Move upward to parent
                if (parent_track.find(current) != parent_track.end() && !visited[parent_track[current]]) {
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
        }

        // Remaining elements in the queue are at distance k
        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }

        return result;
    }
};