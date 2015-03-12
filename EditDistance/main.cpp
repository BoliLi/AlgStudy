#include <iostream>
#include <math.h>
/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character*/
using namespace std;
//DP
//steps[i][j] represents the steps changing word1 in length i to word2 in length j
//Initially, steps[0][j] = j(add j characters), steps[i][0] = i(del i characters)
//steps[i][j] = min(steps[i-1][j]+1(add), steps[i][j-1]-1(del), steps[i-1][j-1]+1(replace))
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int steps[m+1][n+1];
        for(int i = 0; i < m; i++)
            steps[i][0] = i;
        for(int j = 0; j < n; j++)
            steps[0][j] = j;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i] == word2[j]) {
                    steps[i][j] = steps[i-1][j-1];
                } else {
                    steps[i][j] = min(steps[i-1][j]+1, min(steps[i][j-1]+1, steps[i-1][j-1]+1));
                }
            }
        }
        return steps[m][n];
    }
};

int main()
{
    Solution a;

    cout << a.minDistance("abdc", "abc") << endl;
    return 0;
}
