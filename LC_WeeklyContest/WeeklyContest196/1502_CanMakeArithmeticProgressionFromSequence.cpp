//
// Created by Zeno on 2020/7/5.
//

/*
 * Just sort then compute diff
 * time complexity: O(nlogn)
 * space complexity: O(1)
 */

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int diff = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (i == 1) {
                diff = arr[i] - arr[i - 1];
            } else {
                if (arr[i] - arr[i - 1] != diff) {
                    return false;
                }
            }
        }
        return true;
    }
};