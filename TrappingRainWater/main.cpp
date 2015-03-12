#include <iostream>

using namespace std;
//ĳ��ľ�����Ҫ����ߺ��ұ�ͬʱ��ľ����Լ���ʱ��ľ���Ϸ����ܳ�ˮ
class Solution {
public:
    int trap(int A[], int n) {
        int *max_left = new int[n]();
        int *max_right = new int[n]();
        int sum = 0;

        for(int i = 1; i < n - 1; i++) {
            max_left[i] = max(max_left[i - 1], A[i - 1]);
            max_right[n - 1 - i] = max(A[n - i], max_right[n - i]);
        }

        for(int i = 1; i < n - 1; i++) {
            int height = min(max_left[i], max_right[i]);
            if(height > A[i])
                sum += height - A[i];
        }
        return sum;
    }
};

int main()
{
    Solution a;
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 1, 1, 1, 2, 1};
    cout << a.trap(arr, 12) << endl;
    return 0;
}
