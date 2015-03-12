#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> dict;
        map<string, int> rec;
        vector<int> ret;
        int wordCnt = L.size();
        int wordLen = L[0].size();

        for(int i = 0; i < wordCnt; i++) {
            dict[L[i]]++;
        }
        printf("%d\n", dict.size());
        for(int i = 0; i <= S.size() - wordLen * wordCnt; i++) {
            rec.clear();
            int j;
            for(j = 0; j < wordCnt; j++) {
                string word = S.substr(i + j * wordLen, wordLen);
                if(dict.find(word) == dict.end())
                    break;
                rec[word]++;
                if(rec[word] > dict[word])
                    break;
            }
            if(j == wordCnt) {
                ret.push_back(i);
                printf("%d ", i);
            }

        }
        return ret;
    }
};

int main()
{
    string S = "abcbcchjtrebccabc";
    vector<string> L;
    Solution a;

    L.push_back("hjt");
    //L.push_back("bcc");

    a.findSubstring(S, L);
    cout << "Hello world!" << endl;
    return 0;
}
