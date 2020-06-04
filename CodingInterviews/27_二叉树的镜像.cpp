//
// Created by Zeno on 2020/6/4.
//

/*
 * 思路：
 * 前序遍历，遇到有子节点的节点则swap左右子节点
 */

TreeNode* mirrorTree(TreeNode* root) {
    mirrorRecursively(root);
    return root;
}
void mirrorRecursively(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return;
    }

    swap(root->left, root->right);
    if (root->left) {
        mirrorRecursively(root->left);
    }
    if (root->right) {
        mirrorRecursively(root->right);
    }
}