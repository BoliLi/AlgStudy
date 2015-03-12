#include <iostream>
#include <algorithm>
#include <string>
/*Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.*/
using namespace std;

class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1 != l2)
            return false;
        if(l1 == 1)
            return s1[0] == s2[0];
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for(int i = 0; i < l1; i++) {
            if(str1[i] != str2[i])
                return false;
        }

        string s11, s12, s21, s22;
        bool ret = false;
        for(int i = 1; i < l1 && !ret; i++) {
            s11 = s1.substr(0, i);
            s12 = s1.substr(i, l1 - i);
            s21 = s2.substr(0, i);
            s22 = s2.substr(i, l1 - i);
            ret = isScramble(s11, s21) && isScramble(s12, s22);
            if(!ret) {
                s21 = s2.substr(0, l1 - i);
                s22 = s2.substr(l1 - i, i);
                ret = isScramble(s11, s22) && isScramble(s12, s21);
            }
        }
        return ret;
    }
};

int main()
{
    Solution1 a;
    cout << a.isScramble("great", "rgtae") << endl;
    return 0;
}
