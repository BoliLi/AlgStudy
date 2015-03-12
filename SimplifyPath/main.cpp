#include <iostream>
#include <stack>
/*Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".*/
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> smpPath;
        string tmpStr = "";
        string ret = "";
        int needNewStr = 1;

        for(int i = 0; i <= path.size(); i++) {
            if(path[i] == '/' || i == path.size()) {
                if(!needNewStr) {
                    needNewStr = 1;
                    if(tmpStr == "..") {
                        if(smpPath.empty())
                            return "";
                        smpPath.pop();
                    } else if(tmpStr == ".") {
                    } else {
                        smpPath.push(tmpStr);
                    }
                }
                continue;
            }

            if(needNewStr) {
                tmpStr = "";
                needNewStr = 0;
            }

            tmpStr += path[i];
        }

        int j = smpPath.size();
        string str = smpPath.top();
        smpPath.pop();
        ret = "/" + str;
        for(int i = 0; i < j - 1; i++) {
            str = smpPath.top();
            smpPath.pop();
            string tmp = "/" + str;
            ret = tmp + ret;
        }

        return ret;
    }
};

int main()
{
    Solution a;

    cout << a.simplifyPath("/a/b/c/./..") << endl;
    return 0;
}
