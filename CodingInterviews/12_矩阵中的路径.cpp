//
// Created by Zeno on 2020/6/5.
//

/*
 * 思路：
 * 回溯法解决
 * 时间复杂度:O(n)
 * 空间复杂度:O(1)
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int wordIndex, int x, int y) {
        if (board[x][y] != word[wordIndex]) {
            return false;
        }
        if (wordIndex == word.size() - 1) {
            return true;
        }

        char curChar = board[x][y];
        board[x][y] = 0; // 将此位置标记，避免走到走过的位置
        wordIndex++;

        if ((x > 0 && backtrack(board, word, wordIndex, x - 1, y))
            || (y > 0 && backtrack(board, word, wordIndex, x, y - 1))
            || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y))
            || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))) {
            return true;
        }

        board[x][y] = curChar; // 取消标记，开始回溯
        return false;
    }
};