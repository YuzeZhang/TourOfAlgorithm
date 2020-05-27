//
// Created by Zeno on 2020/5/27.
//

/*
 * 思路：
 * 为了实现Z字形打印，需要两个栈来存储节点
 * 奇数层（1、3、5...）的子节点从左到右入栈（由于FILO，奇数层的下一层（偶数层）的打印顺序是从右到左的）
 * 偶数层（2、4、6...）的子节点从右到左入栈（由于FILO，偶数层的下一层（奇数层）的打印顺序是从左到右的）
 * time complexity:O(n)
 * space complexity:O(n)
 */

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    stack<TreeNode*> levels[2];
    int curLevel = 0;
    int nextLevel = 1;
    levels[curLevel].push(root);
    vector<int> levelVal;
    while (!levels[curLevel].empty() || !levels[nextLevel].empty()) {
        TreeNode* cur = levels[curLevel].top();
        levels[curLevel].pop();
        levelVal.push_back(cur->val);

        if (curLevel == 0) {
            if (cur->left) {
                levels[nextLevel].push(cur->left);
            }
            if (cur->right) {
                levels[nextLevel].push(cur->right);
            }
        } else {
            if (cur->right) {
                levels[nextLevel].push(cur->right);
            }
            if (cur->left) {
                levels[nextLevel].push(cur->left);
            }
        }

        if (levels[curLevel].empty()) {
            res.push_back(levelVal);
            levelVal.clear();

            curLevel = 1 - curLevel;
            nextLevel = 1 - nextLevel;
        }
    }
    return res;
}