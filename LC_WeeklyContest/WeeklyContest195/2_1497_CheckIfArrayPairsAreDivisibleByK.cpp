//
// Created by Zeno on 2020/6/29.
//

/*
 * 思路：
 * 将所有的余数进行排序，排序后第一个与最后一个加起来应该是k，第二个与倒数第二个加起来也是k....
 * （或者说和为k的两个余数的个数应该相等）
 * 同时，如果余数0的个数不为偶数，那么也无法配对
 * (num % k + k) % k能使余数由负数转化为正数
 * 时间复杂度：O(n+k)
 * 空间复杂度：O(k)
 */
bool canArrange(vector<int>& arr, int k) {
    map<int, int> mp;
    for (int num : arr) {
        int mod = (num % k + k) % k;
        mp[mod]++;
    }
    if (mp[0] % 2 != 0) {
        return false;
    }
    for (int i = 1; i < k; i++) {
        if (mp[i] != mp[k - i]) {
            return false;
        }
    }
    return true;
}