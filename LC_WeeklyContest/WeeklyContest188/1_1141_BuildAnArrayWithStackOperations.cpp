//
// Created by Zeno on 2020/5/10.
//

/*
 * 中文站题目：5404.用栈操作构建数组
 * 思路：从[1,n]中取数字i，若与target[j]相同，则"Push"，否则"Push"之后"Pop"
 * 时间复杂度：O(target.size() + n)
 * 空间复杂度：O(1)
 */

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int size = target.size();
        if (size == 0) {
            return res;
        }

        int i = 1;
        for (int j = 0; j < size; j++) {
            for (; i <= n; i++) {
                res.push_back("Push");
                if (target[j] == i) {
                    i++;
                    break;
                } else {
                    res.push_back("Pop");
                }
            }
        }

        return res;
    }
};