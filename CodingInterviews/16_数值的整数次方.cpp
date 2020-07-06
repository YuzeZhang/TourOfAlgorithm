//
// Created by Zeno on 2020/7/6.
//

// 使用快速幂求解
// 时间复杂度:O(log2n)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long num = n;
        if (num < 0) {
            num = -num;
            x = 1 / x;
        }
        while (num) {
            if (num & 1) {
                ans *= x;
            }
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};