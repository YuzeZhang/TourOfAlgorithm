//
// Created by Zeno on 2020/6/20.
//

/*
 * 思路：
 * 在一些数的和一定，求怎样分解能让这些数的乘积最大这个问题中，3的数量越多，乘积就越大，其次是2
 * 但当和被3除余1时，应该减少一个3，和余数凑成2*2
 */

int cuttingRope(int n) {
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }

    int timesOf3 = n / 3;
    if (n - timesOf3 * 3 == 1) {
        timesOf3--;
    }
    int timesOf2 = (n - 3 * timesOf3) / 2;

    return (int) (pow(3, timesOf3)) * (pow(2, timesOf2));
}
