//
// Created by Zeno on 2020/6/23.
//

/*
 * 思路：
 * 使用取模的方式从右向左遍历数字，可以省掉数字转成字符串所需的O(n)空间
 * 状态:dp[i]表示从右向左数的i位数的可能的翻译方法数之和
 * 转移方程：
 * dp[i] = dp[i - 1](第i个和第i -2个数字组成的两位数不在[10,25]区间内)
 * dp[i] = dp[i - 1] + dp[i - 2](第i个和第i - 2个数字组成的两位数在[10,25]区间内)
 */

class Solution {
public:
    int translateNum(int num) {
        int count = 1; // 用于存储dp[i - 1]
        int prev_count = 0; // 用于存储dp[i - 2]
        int prev = -1; // 用于存储第i - 1个数
        while (num) {
            int cur = num % 10; // 用于存储第i个数
            int temp; // 用于存储dp[i]
            num /= 10;
            if (prev != -1) {
                int doubleDigit = cur * 10 + prev;
                if (doubleDigit >= 10 && doubleDigit <= 25) {
                    temp = count + prev_count;
                } else {
                    temp = count;
                }
            }
            prev = cur;
            prev_count = count;
            count = temp;
        }
        return count;
    }
};