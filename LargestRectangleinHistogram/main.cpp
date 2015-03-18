#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
//See http://blog.csdn.net/doc_sgl/article/details/11805519
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
