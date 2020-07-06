//
// Created by Zeno on 2020/7/7.
//

/*
 * a ^ b 可以算出a + b没有进位的和
 * (a & b) << 1可以算出a + b的进位
 * a ^ b + ((a & b) << 1) 其实就是答案，但是不能用加法，所以递归/循环调用直到b为0
 */

class Solution {
public:
    int add(int a, int b) {
        if (b == 0) {
            return a;
        }

        return add(a ^ b, (unsigned int)(a & b) << 1);
    }
};
