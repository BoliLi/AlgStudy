#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
/*Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.*/
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > wordMap;
        vector<string> ret;

        for(string str : strs) {
            string orgStr = str;
            sort(str.begin(), str.end());
            //cout << str << endl;
            wordMap[str].push_back(orgStr);
        }

        for(auto it = wordMap.begin(); it != wordMap.end(); it++) {
            if(it->second.size() > 1) { //至少有两个字符串是回文字符串
                for(string str : it->second) {
                    cout << str << endl;
                    ret.push_back(str);
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> strs;
    Solution a;

    strs.push_back("fdbe");
    strs.push_back("dbfe");
    strs.push_back("jtioerj");
    a.anagrams(strs);
    cout << "Hello world!" << endl;
    return 0;
}
