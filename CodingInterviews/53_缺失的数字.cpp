//
// Created by Zeno on 2020/6/20.
//

int missingNumber(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return -1;
    }
    if (nums[0] != 0) {
        return 0;
    }
    for (int i = 0; i <= size - 2; i++) {
        int next = nums[i] + 1;
        if (nums[i + 1] != next) {
            return next;
        }
    }
    return nums[size - 1] + 1;
}