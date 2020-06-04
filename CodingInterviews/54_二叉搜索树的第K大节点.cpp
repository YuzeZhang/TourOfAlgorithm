//
// Created by Zeno on 2020/6/4.
//

/*
 * 思路：二叉搜索树中序遍历（先右后左）
 */

int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> nodes;
    int count = 0;
    TreeNode* cur = root;
    nodes.push(root);
    while (cur || !nodes.empty()) {
        if (cur) {
            nodes.push(cur);
            cur = cur->right;
        } else {
            cur = nodes.top();
            nodes.pop();
            count++;
            if (count == k) {
                return cur->val;
            }
            cur = cur->left;
        }
    }
    return INT_MIN;
}