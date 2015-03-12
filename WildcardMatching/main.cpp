#include <iostream>
/*Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false*/
using namespace std;

class Solution {
public:
    bool isMatch(char *s, char *p) {
        char *markP = NULL, *markS = NULL;
        while(*s) {
            if(*p == *s || *p == '?') {
                p++;
                s++;
                continue;
            }
            if(*p == '*') {
                markP = p;
                markS = s;
                p++;
                continue;
            }
            if(markP != NULL) { //����
                s = markS + 1;
                p = markP + 1;
                markS++;
                continue;
            }
            return false;
        }
        while(*p == '*')
            p++;
        return *p == '\0';
    }
};

int main()
{
    Solution a;
    cout << a.isMatch("abcdcccdaa", "ab*cd*ab") << endl;
    return 0;
}
