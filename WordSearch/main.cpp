#include <iostream>
#include <vector>
/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.*/
using namespace std;

class Solution {
    bool dfs(vector<vector<char> > &board, string word, int i, int j, int idx, vector<vector<bool> > &visited) {
        int m = board.size();
        int n = board[0].size();
        bool ret = false;

        if(i < 0 || i >= m || j < 0 || j >=n)
            return false;

        if(visited[i][j] == true)
            return false;

        if(board[i][j] != word[idx])
            return false;

        if(board[i][j] == word[idx] && idx == word.size() - 1)
            return true;

        visited[i][j] = true;
        ret |= dfs(board, word, i - 1, j, idx + 1, visited);
        ret |= dfs(board, word, i + 1, j, idx + 1, visited);
        ret |= dfs(board, word, i, j - 1, idx + 1, visited);
        ret |= dfs(board, word, i, j + 1, idx + 1, visited);
        visited[i][j] = false;

        return ret;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, word, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    string word = "ABCESFCSADEE";
    vector<vector<char> > board(3, vector<char>(4, 'A'));
    Solution a;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            board[i][j] = word[i * 4 + j];
        }
    }

    cout << a.exist(board, "SEE") << endl;
    return 0;
}
