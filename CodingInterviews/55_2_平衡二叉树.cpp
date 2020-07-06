//
// Created by Zeno on 2020/7/7.
//

/*
 * 思路：
 * 当前节点的最大深度 = max(左子树的最大深度,右子树的最大深度) + 1
 * 进行后序遍历，自底向上最后算出root的左右子树最大深度
 * 同时若有任意一个节点不平衡（即左右子树最大深度差超过1）则整个树为不平衡（剪枝降低复杂度）
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return diff(root) != -1;
    }
private:
    int diff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = diff(root->left);
        if (left == -1) {
            return -1;
        }
        int right = diff(root->right);
        if (right == -1) {
            return -1;
        }

        return std::abs(left - right) < 2 ? std::max(left, right) + 1 : -1;
    }
};