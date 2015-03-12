#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int result = 0;
        while(start < end) {
            int area = min(height[start], height[end]) * (start - end);
            result = max(result, area);
            if(height[start] < height[end])
                start++;
            else
                end++;
        }
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
