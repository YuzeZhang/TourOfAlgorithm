//
// Created by Zeno on 2020/5/11.
//

/*
 * 思路：当前节点的深度 = max(左子节点的深度， 右子节点的深度) + 1
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    if (root->left == nullptr) {
        return maxDepth(root->right) + 1;
    }
    if (root->right == nullptr) {
        return maxDepth(root->left) + 1;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}