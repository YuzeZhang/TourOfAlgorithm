//
// Created by Zeno on 2020/7/6.
//

/*
 * 思路：
 * B[i] = A中的每个元素相乘，excluding A[i] = A[i]左边所有元素的乘积 * A[i]右边所有元素的乘积
 * left表示A[i]左边所有元素的乘积，right表示A[i]右边所有元素的乘积
 * left和right都不包括A[i]因为是先乘入ans中再更新left和right
 */

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int size = a.size();
        vector<int> ans(size, 1);
        int left = 1;
        int right = 1;

        for (int i = 0; i < size; i++) {
            ans[i] *= left;
            left *= a[i];
        }
        for (int i = size - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= a[i];
        }
        return ans;
    }
};