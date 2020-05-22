//
// Created by Zeno on 2020/5/20.
//

/*
 * 思路：遍历字符串，看当前字符串是否和上一个相同，由此判断是否处在一个non-empty substring that
 * contains only one unique character中
 * time complexity：O(n)
 * space complexity：O(1)
 */

int maxPower(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int curPower = 0;
    int maxPower = 0;
    char lastChar = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == lastChar) {
            curPower++;
            maxPower = std::max(maxPower, curPower);
        } else {
            lastChar = s[i];
            curPower = 0;
        }
    }
    maxPower++;
    return maxPower;
}