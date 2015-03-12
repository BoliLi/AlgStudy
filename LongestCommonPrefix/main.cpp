#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i, j;
        if(strs.size() == 0)
            return "";
        string prefix = strs[0];
        int len;
        for(i = 1; i < strs.size(); i++) {
            string str = strs[i];
            len = min(prefix.length(), str.length());

            for(j = 0; j < len; j++) {
                if(str[j] != prefix[j])
                    break;
            }

            if(j == 0)
                return "";
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
