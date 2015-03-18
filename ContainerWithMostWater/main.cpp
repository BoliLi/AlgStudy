#include <iostream>
/*Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines 
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container.*/
using namespace std;
//×óÓÒ¼Ğ±Æ£¬ÄÄ±ßÊÇ¶Ì°åÔòÄÄ±ßÏòÖĞ¼äÒÆ¶¯
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
