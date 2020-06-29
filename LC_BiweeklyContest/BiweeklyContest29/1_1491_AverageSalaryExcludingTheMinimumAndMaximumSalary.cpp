//
// Created by Zeno on 2020/6/29.
//

// tips:要注意读题，excluding的意思是除了

double average(vector<int>& salary) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto num : salary) {
        max = (num > max) ? num : max;
        min = (num < min) ? num : min;
    }
    double count = 0;
    double sum = 0;
    for (auto num : salary) {
        if (num == min || num == max) {
            continue;
        }
        count++;
        sum += num;
    }
    return sum / count;
}