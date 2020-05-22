//
// Created by Zeno on 2020/5/20.
//

/*
 * 思路：分母和分子分别遍历
 * time complexity:O(n^3)
 * space complexity:O(1)
 */

bool isSimplified(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    for (int i = 2; i <= a; i++) {
        if (a % i == 0) {
            if (b % i == 0) {
                return false;
            }
        }
    }
    return true;
}
vector<string> simplifiedFractions(int n) {
    vector<string> res;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (!isSimplified(i, j)) {
                continue;
            }
            string s;
            s += to_string(j);
            s.push_back('/');
            s += to_string(i);
            res.push_back(s);
        }
    }
    return res;
}