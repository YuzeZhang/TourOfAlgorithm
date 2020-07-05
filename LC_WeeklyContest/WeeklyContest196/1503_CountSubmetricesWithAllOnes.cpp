//
// Created by Zeno on 2020/7/5.
//

/*
 * First, find the solution to count consecutive ones in one row.
 * Then "compress" the 2D array to the 1D array.
 * space: O(1)
 * time: O(M * N * M)
 */

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();

        int ans = 0;
        for (int up = 0; up < M; up++) {
            vector<int> tmp(N, 1);
            for (int down = up; down < M; down++) {
                for (int i = 0; i < N; i++) {
                    tmp[i] &= mat[down][i];
                }
                ans += countOneRow(tmp);
            }
        }
        return ans;
    }
private:
    int countOneRow(const vector<int>& row) {
        int res = 0, length = 0;
        for (int i = 0; i < row.size(); i++) {
            length = row[i] != 1 ? 0 : length + 1;
            res += length;
        }
        return res;
    }
};