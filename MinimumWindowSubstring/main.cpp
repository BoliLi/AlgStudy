#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
    int cnt = 0;
public:
    string minWindow(string S, string T) {
        int size1 = S.size();
        int size2 = T.size();

        vector<int> needCount(128, 0);  //A~Z,a~z ascii code is less than 128
        vector<int> findCount(128, 0);

        //construct needCount, which represents chars in T
        for(int i = 0; i < size2; i ++)
            needCount[T[i]] ++;

        int minBegin = 0;       //min window begin position
        int minEnd = size1 - 1; //min window end position
        int minWidth = INT_MAX; //INT_MAX means not exist

        int begin = 0;  //cur window begin position
        int end = 0;    //cur window end position
        int width = end-begin+1;
        //number of chars in T that included in S(begin, width)
        int curCount = 0;

        for(; end < size1; end ++)
        {
            cnt++;
            //skip chars not in T
            while(end < size1 && needCount[S[end]] == 0)
                end ++;

            //to here, S[end] in T
            findCount[S[end]] ++;
            //only needCount[S[end]] chars are needed to find
            if(findCount[S[end]] <= needCount[S[end]])
                curCount ++;

            if(curCount == size2)
            {//find all, and shrink the window
                //check shrink1 and shrink2 alternately
                while(begin < end)
                {
                    cnt++;
                    if(needCount[S[begin]] == 0)
                    {//shrink 1: skip needless chars in cur window
                        begin ++;
                        continue;
                    }
                    //to here, needCount[S[begin]] != 0
                    else if(findCount[S[begin]] > needCount[S[begin]])
                    {//shrink 2: skip redundant chars in cur window
                        findCount[S[begin]] --;
                        begin ++;
                        continue;
                    }
                    else
                        break;
                }

                //shrink finish
                width = end-begin+1;
                if(width < minWidth)
                {
                    minBegin = begin;
                    minEnd = end;
                    minWidth = width;
                }

                end++;
                begin = end;
                curCount = 0;
                for(int i = 0; i < size2; i ++)
                    findCount[T[i]] = 0;
            }
        }
        cout << cnt << endl;
        if(minWidth == INT_MAX)
            return "";
        else
            return S.substr(minBegin, minWidth);
    }
};

int main()
{
    Solution a;

    cout << a.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
