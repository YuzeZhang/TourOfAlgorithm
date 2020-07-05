//
// Created by Zeno on 2020/7/5.
//

/*
 * 思路：
 * 先将数组中的数转成string类型并存储到数组中（不能存到一个string中否则分不清不同位数的数字）
 * 使用自定义compare函数（lambda表达式）对字符串数组进行排序
 * compare函数：
 * 对于字符串"30"和"5"来说，用字典序排序即可
 * 对于字符串"30"和"3"来说，在字典序中"3" < "30"，但是不是我们想要的结果，因为要组成更小的数，30放在前面更好
 * 于是将"30"和"3"分别组合成"303"和"330"（也就是str1 + str2和str2 + str1），并对其进行排序
 */

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> numsStr;
        string ans = "";
        for (int num : nums) {
            numsStr.push_back(to_string(num));
        }
        std::sort(numsStr.begin(), numsStr.end(), [](string& str1, string& str2){return str1 + str2 < str2 + str1;});
        for (string num : numsStr) {
            ans += num;
        }
        return ans;
    }
};