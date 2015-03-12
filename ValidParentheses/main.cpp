#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2)
            return false;

        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
            char a = s[i];
            if(a == '(' || a == '[' || a == '{')
                stk.push(a);
            else {
                if(a == ')') {
                    if(stk.empty() || stk.top() != '(')
                        return false;
                    else
                        stk.pop();
                }

                if(a == '}') {
                    if(stk.empty() || stk.top() != '{')
                        return false;
                    else
                        stk.pop();
                }

                if(a == ']') {
                    if(stk.empty() || stk.top() != '[')
                        return false;
                    else
                        stk.pop();
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution a;

    cout << a.isValid("(){()()]()") << endl;
    return 0;
}
