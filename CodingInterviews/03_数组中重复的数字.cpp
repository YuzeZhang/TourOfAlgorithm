//
// Created by Zeno on 2020/6/3.
//

// 1. 用map，空间换时间，空间O(n)时间O(n)
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto num : nums) {
        if (mp[num] == 0){
            mp[num]++;
        } else {
            return num;
        }
    }
    return -1;
}

// 2. 排序，时间换空间，空间O(1)时间O(nlogn)
int findRepeatNumber(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return nums[i];
        }
    }
    return -1;
}