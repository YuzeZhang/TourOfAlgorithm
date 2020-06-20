//
// Created by Zeno on 2020/6/20.
//

class Solution {
public:
    int movingCount(int m, int n, int k) {
        chessBoard = new int[m][n];
        countSquares = 0;
        backtrace(0, 0, m, n, k);
        return countSquares;
    }

private:
    int **chessBoard; // 记录棋盘上的位置能否到达，0表示未知，1表示可以到达，2表示不能到达
    int countSquares;

    bool isLegal(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        if (sum > k) {
            return false;
        }
        return true;
    }

    void backtrace(int x, int y, int m, int n, int k) {
        if (x >= m || y >= n) {
            return;
        }
        if (chessBoard[x][y] == 1 || chessBoard[x][y] == 2) {
            return;
        }

        if (isLegal(x, y, k)) {
            countSquares++;
        } else {
            return;
        }

        backtrace(x + 1, y, m, n, k);
        backtrace(x, y + 1, m, n, k);
        backtrace(x - 1, y, m, n, k);
        backtrace(x, y - 1, m, n, k);
    }
};
