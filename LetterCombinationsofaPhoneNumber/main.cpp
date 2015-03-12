#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const string keyboard[10] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(vector<string> &result, string words, string digits, int curPos) {
        int i;

        if(curPos == digits.length()) {
            cout << words << endl;
            result.push_back(words);
            return;
        }
        string btn = keyboard[digits[curPos] - '0'];
        for(i = 0; i < btn.length(); i++) {
            dfs(result, words + btn[i], digits, curPos + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        dfs(ret, "", digits, 0);
        return ret;
    }

    void test(string a) {
        string btn = "abc";
        a += btn[1];
        cout << a << endl;
    }
};

int main()
{
    Solution a;
    vector<string> rt;

    rt = a.letterCombinations("233");
    cout << "Hello world!" << endl;
    return 0;
}
