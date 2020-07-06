//
// Created by Zeno on 2020/7/7.
//

/*
 * 思路：
 * 用两次二分法，分别找到target和target - 1右边的位置
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target) - binarySearch(nums, 0, nums.size() - 1, target - 1);
    }
private:
    int binarySearch(const vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};