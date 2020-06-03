//
// Created by Zeno on 2020/6/3.
//

/*
 * 思路：
 * 把数据等分成两个部分，左边的部分用最大堆来存储，右边的部分用最小堆来存储
 * 也就是说，最小堆中的所有元素都大于最大堆中所有元素
 * 此时，若元素总数为奇数，中位数为最大堆的堆顶元素（奇数时令最大堆元素比最小堆元素多1）
 * 若元素总数为偶数，中位数为最大堆的堆顶元素与最小堆的堆顶元素的平均值
 * time complexity:O(logn)
 * space complexity:O(n)
 */
class MedianFinder {
    priority_queue<int> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min heap
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    // add的时候先将元素插入最大堆，当最大堆元素多于最小堆时再调整
    // 插入最大堆之前先通过最小堆保证插入的元素不会比最小堆中的大
    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};