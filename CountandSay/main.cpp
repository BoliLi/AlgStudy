#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.*/
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret;
        char a[10] = {0};
        char retStr[1024] = {0};
        int i, start, end;

        itoa(n, a, 10);
        end = 0;
        while(a[end++] != '\0');
        memcpy(retStr, a, end - 1);

        end--;
        start = 0;
        for(i = 0; i < n; i++) {
            int newStart = end;
            int newEnd = end;
            while(start < end) {
                int cnt = 1;
                while(retStr[start] == retStr[start + 1]) {
                    cnt++;
                    start++;
                }
                itoa(cnt, a, 10);
                int len = 0;
                while(a[len++] != '\0');
                memcpy(retStr + newEnd, a, len - 1);
                newEnd += len - 1;
                retStr[newEnd++] = retStr[start];
                start++;

            }
            start = newStart;
            end = newEnd;
            printf("%s\n", retStr);
        }
        cout << ret << i <<endl;
        return ret;
    }
};

int main()
{
    Solution a;
    a.countAndSay(5);
    cout << "Hello world!" << endl;
    return 0;
}
