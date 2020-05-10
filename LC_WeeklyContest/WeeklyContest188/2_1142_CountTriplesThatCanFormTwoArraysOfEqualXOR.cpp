//
// Created by Zeno on 2020/5/10.
//

/*
 * 中文站题目：5405.形成两个异或相等数组的三元组数目
 * 思路：
 * a ^ b == 0 <==> a == b
 * 在题目中，要找能够使a == b的三元组，由上面的公式可以转化为
 * 找能使arr[i]到arr[k]异或的结果为0的i、k
 * i、k确定后j的值不影响结果，在i、k之间的所有数都可以成为j*/
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        if (arr.size() < 2) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int XOR = arr[i];
            for (int k = i + 1; k < arr.size(); k++) {
                XOR ^= arr[k];
                // 注意：此判断条件不能写在外层循环中，否则每次k的值都为size
                if (XOR == 0) {
                    res += k - i; // j可以取的数目为k - i
                }
            }
        }
        return res;
    }
}
};

#if 0
// 超时的暴力解法
int getExclusiveOR(const vector<int> &arr, int start, int end) {
    int res = 0;
    for (int i = start; i <= end; i++) {
        res ^= arr[i];
    }
    return res;
}

int countTriplets(vector<int> &arr) {
    int size = arr.size();
    if (size < 2) {
        return 0;
    }
    int res = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j; k < size; k++) {
                int a = getExclusiveOR(arr, i, j - 1);
                int b = getExclusiveOR(arr, j, k);
                if (a == b) {
                    res++;
                }
            }
        }
    }

    return res;
}
#endif
