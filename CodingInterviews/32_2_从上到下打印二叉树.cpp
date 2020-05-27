//
// Created by Zeno on 2020/5/27.
//

/*
 * 思路：
 * 使用队列存储节点即可做到层序遍历节点
 * 使用两个变量分别记录下一层的节点数和当前层还需要打印的节点数，即可做到每层打印到一行
 * time complexity:O(n)
 * space complexity:O(n)
 */

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode*> que;
    que.push(root);
    int nodesInNextLevel = 0;
    int toBePrinted = 1;
    vector<int> level;
    while (!que.empty()) {
        TreeNode* cur = que.front();
        que.pop();
        toBePrinted--;
        level.push_back(cur->val);

        if (cur->left) {
            que.push(cur->left);
            nodesInNextLevel++;
        }
        if (cur->right) {
            que.push(cur->right);
            nodesInNextLevel++;
        }

        if (toBePrinted == 0) {
            res.push_back(level);
            level.clear();
            toBePrinted = nodesInNextLevel;
            nodesInNextLevel = 0;
        }

    }
    return res;
}