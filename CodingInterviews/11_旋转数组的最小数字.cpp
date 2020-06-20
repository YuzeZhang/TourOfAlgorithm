//
// Created by Zeno on 2020/6/15.
//
// [1, 2, 3, 4, 5]、[3, 4, 5, 1, 2]、[2, 3, 4, 5 ,1]
int minArray(vector<int> &numbers) {
    int size = numbers.size();
    if (size == 0) {
        return INT_MIN;
    }

    int left = 0;
    int right = size - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] < numbers[right]) {
            right = mid;
        } else if (numbers[mid] == numbers[right]) {
            right--;
        } else {
            left = mid + 1;
        }
    }
    return numbers[left];
}