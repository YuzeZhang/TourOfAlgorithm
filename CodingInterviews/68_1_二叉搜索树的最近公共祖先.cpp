//
// Created by Zeno on 2020/7/3.
//

/*
 * Thought process:
 * Use two vectors to record the path to the node, then traversal two paths respectively
 * and find the first node which is different in two paths.
 *
 * time complexity: O(logn)
 * space complexity: O(logn)
 *
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findNode(root, p, path1);
        findNode(root, q, path2);

        TreeNode* ans = nullptr;
        int i = 0;
        for (; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) {
                if (i > 0) {
                    return path1[i - 1];
                } else {
                    return nullptr;
                }
            }
        }
        if (i == path1.size()) {
            return path1[path1.size() - 1];
        } else {
            return path2[path2.size() - 1];
        }
    }

private:
    void findNode(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (target == nullptr) {
            return;
        }
        while (root != nullptr) {
            if (root != target) {
                if (root->val > target->val) {
                    path.push_back(root);
                    root = root->left;
                } else if (root->val < target->val) {
                    path.push_back(root);
                    root = root->right;
                }
            } else {
                path.push_back(root);
                return;
            }
        }
    }
};