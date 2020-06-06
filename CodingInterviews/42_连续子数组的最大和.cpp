//
// Created by Zeno on 2020/6/6.
//

int maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int maxSum = INT_MIN;
    for (int num : nums) {
        if (curSum >= 0) {
            curSum += num;
        } else {
            curSum = num;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}