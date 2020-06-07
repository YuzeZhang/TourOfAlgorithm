//
// Created by Zeno on 2020/6/7.
//

/*
 * 思路：
 * 使用优先级队列找出K个比median大的数
 */

vector<int> getStrongest(vector<int>& arr, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> strongest;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    int median = arr[(size - 1) / 2];
    for (int num : arr) {
        int diff = abs(num - median);
        if (strongest.size() < k) {
            strongest.push(make_pair(diff, num));
        } else {
            strongest.push(make_pair(diff, num));
            strongest.pop();
        }
    }
    vector<int> res;
    while (!strongest.empty()) {
        res.push_back(strongest.top().second);
        strongest.pop();
    }
    return res;
}