#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
//可以维护一个递增的栈，每次比较栈顶与当前元素。如果当前元素小于栈顶元素，则入栈，
//否则出栈并计算当前元素到出栈元素之间的面积，直至栈顶元素小于当前元素。结尾时入栈元素 0，
//重复合并一次。
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int result = 0;
        int i = 0;
        while(i < height.size()) {
            if(s.empty() || height[i] > height[s.top()])
                s.push(i++);
            else {
                int tmp = s.top();
                int curRes = 0;
                s.pop();
                curRes = height[tmp] * (s.empty() ? i : i - s.top() - 1);
                result = max(result, curRes);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> height(7, 0);
    Solution a;
    height[0] = 2;
    height[1] = 5;
    height[2] = 6;
    height[3] = 4;
    height[4] = 6;
    height[5] = 7;
    height[6] = 5;
    cout << a.largestRectangleArea(height) << endl;
    return 0;
}
