//
// Created by Zeno on 2020/5/20.
//

/*
 * 思路：dfs
 */

void dfs(TreeNode* root, vector<int>& path, int& res) {
    if (root == nullptr) {
        return;
    }

    int val = root->val;
    path.push_back(val);

    if (std::max(path.begin(), path.end()) == val) {
        res++;
    }

    dfs(root->left, path, res);
    dfs(root->right, path, res);
    path.pop_back();
}
int goodNodes(TreeNode* root) {
    vector<int> path;
    int res = 0;
    dfs(root, path, res);
    return res;
}