//
// Created by Zeno on 2020/6/2.
//

/*
 * 思路：
 * 1. 使用string::find_first_not_of和string::find_last_not_of来去除字符串首尾的空格
 * 2. 通过找到'e'的位置将字符串分割成底数和指数两部分
 * 3. 对底数和指数分别进行判断
 * time complexity: O(n)
 * space complexity: O(1)
 */
bool isNumber(string s) {
    // 去除首尾空格
    int i = s.find_first_not_of(' ');
    // string::npos = -1
    if (i == string::npos) {
        return false;
    }
    int j = s.find_last_not_of(' ');
    s = s.substr(i, j - i + 1);
    if (s.empty()) {
        return false;
    }

    // 通过e的位置将字符串分为两部分
    int ePos = s.find('e');
    if (ePos == string::npos) {
        return judgeP(s);
    } else {
        return judgeP(s.substr(0, ePos)) && judgeS(s.substr(ePos + 1));
    }
}

// 判断底数合法
bool judgeP(string s) {
    // num的作用是保证字符串中至少有一位数字
    bool num = false, dot = false;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) {
                return false;
            }
        } else if (s[i] == '.') {
            if (dot) {
                return false;
            } else {
                dot = true;
            }
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            num = true;
        }
    }
    return num;
}

// 判断指数合法
bool judgeS(string s) {
    bool num = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) {
                return false;
            }
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            num = true;
        }
    }
    return num;
}