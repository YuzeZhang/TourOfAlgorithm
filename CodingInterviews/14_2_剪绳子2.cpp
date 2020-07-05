//
// Created by Zeno on 2020/7/6.
//

/*
 * 思路：
 * 计算思路与剪绳子1一样
 * 区别在于涉及到大数越界的情况下取模运算的问题，可以用循环求余法解决求`(x ^ a) % p`的问题
 */

// 循环求余法，求(x ^ a) % p
int remainder(int x, int a, int p) {
    int rem = 1;
    for (int i = 0; i < a; i++) {
        rem = rem * x % p;
    }
    return rem;
}

// 快速幂求余，求(x ^ a) % p
int remainder(int x, int a, int p) {
    int rem = 1;
    while (a > 0) {
        if (a % 2) {
            rem = rem * x % p;
        }
        x = std::pow(x, 2) % p;
        a /= 2;
    }
    return rem;
}

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int numOf3 = n / 3;
        int numOf2 = 0;
        long remainder = 1;
        if (n % 3 == 1) {
            numOf3--;
        }
        numOf2 = (n - numOf3 * 3) / 2;
        for (int i = 0; i < numOf2; i++) {
            remainder = remainder * 2 % 1000000007;
        }
        for (int i = 0; i < numOf3; i++) {
            remainder = remainder * 3 % 1000000007;
        }
        return remainder;
    }
};