//
// Created by Zeno on 2020/5/10.
//

/*
 * 思路：
 * 最小的组成n的round number的数量就是n中所有非零位的位数
 * 每个非零位乘它对应的power，加起来的和就是n
 * 时间复杂度：O(log10n)
 * 空间复杂度：O(1)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        int power = 1;
        while (n > 0) {
            if (n % 10 > 0) {
                ans.push_back((n % 10) * power);
            }
            n /= 10;
            power *= 10;
        }
        cout << ans.size() << endl;
        for (auto number : ans){
            cout << number << " ";
        }
        cout << endl;
    }
}