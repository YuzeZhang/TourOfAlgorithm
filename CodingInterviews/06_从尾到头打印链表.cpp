//
// Created by Zeno on 2020/6/5.
//

/*
 * 思路：
 * 正着遍历然后reserve
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* cur = head;
        vector<int> res;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        std::reserve(res.begin(), res.end());
        return res;
    }
};