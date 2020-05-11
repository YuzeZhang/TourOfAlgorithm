//
// Created by Zeno on 2020/5/11.
//

/*
 * 思路：
 * 本质上是对二叉树进行两次前序遍历，一次先遍历左子节点，一次先遍历右子节点
 * 如果这两次遍历的结果相同（包括空节点的位置），说明该二叉树对称
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root, root);
}

bool isSymmetric(TreeNode* node1, TreeNode* node2) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    if (node1->val != node2->val) {
        return false;
    }

    return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
}