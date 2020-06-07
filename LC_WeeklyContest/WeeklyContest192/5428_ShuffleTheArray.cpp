//
// Created by Zeno on 2020/6/7.
//

/*
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2 * n, 0);
    for (int i = 0; i < n; i++) {
        res[2 * i] = nums[i];
        res[2 * i + 1] = nums[i + n];
    }
    return res;
}
