//
// Created by Zeno on 2020/6/29.
//

/*
 * 思路：
 * 用一个变量保存可以包含一个0的当前子串的长度
 * 用一个变量保存不包含0的当前子串的长度
 * time complexity: O(n)
 */
int longestSubarray(vector<int>& nums) {
    int containOneOfZero = 0;
    int containNonOfZero = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            containOneOfZero++;
            containNonOfZero++;
            ans = std::max(containOneOfZero, ans);
        } else {
            containOneOfZero = containNonOfZero;
            containNonOfZero = 0;
        }
    }
    if (ans == nums.size()) {
        ans--;
    }
    return ans;
}