//
// Created by Zeno on 2020/5/22.
//

/*
 * 思路：
 * 这是一道完全背包问题，一般看到（恰好）构成target的字样，大多与背包有关，因为本题每个数字可以无限选，所以是完全背包
 * 状态:dp[i][j]表示前i个元素，恰好构成成本为j时，所能组成的最大的数
 * 转移方程：dp[i][j] = max(dp[i - 1][j], dp[i][j - cost[i]] + value[i];
 * 初始状态：dp[0][0] = 0, dp[0][i]不存在
 * time complexity:O(n)
 * space complexity:O(n)
 */

string dp[9 + 1][5000 + 1];

string string_max(const string& lhs, const string& rhs) {
    if (lhs.size() > rhs.size()) return lhs;
    if (rhs.size() > lhs.size()) return rhs;

    if (lhs > rhs) {
        return lhs;
    }
    return rhs;
}

string largestNumber(vector<int>& cost, int target) {

    for (int i = 0; i <= target; i++) {
        dp[0][i] = '#';
    }
    dp[0][0] = "";
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= target; j++) {
            string check, uncheck;
            // 不选第i个
            uncheck = dp[i - 1][j];
            // 选上第i个
            if (j - cost[i - 1] >= 0 && dp[i][j - cost[i - 1]] != "#") {
                check = to_string(i) + dp[i][j - cost[i - 1]];
            }
            dp[i][j] = string_max(check, uncheck);
        }
    }
    if (dp[9][target] == "#") {
        return "0";
    }
    return dp[9][target];
}