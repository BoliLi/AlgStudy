#include <iostream>
#include <vector>
/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.*/
using namespace std;
//Binary search
class Solution { // Able to solve duplicates
public:
    int findMin(vector<int> &num) {
        return getMin(num, 0, num.size() - 1);
    }
private:
    int getMin(vector<int> &num, int beg, int end) {
        if(beg == end - 1)
            return min(num[beg], num[end]);
        int med = (beg + end) / 2;
        if(num[beg] > num[med])
            return getMin(num, beg, med);
        else if(num[med] > num[end])
            return getMin(num, med, end);
        else
            return min(getMin(num, beg, med), getMin(num, med, end));
    }
};

class Solution1 {
public:
    int findMin(vector<int> &num) {
        int size = num.size() - 1;
        int l = 0;
        int r = size;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] > num[size]) {
                //left
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return num[l];
    }
};

int main()
{
    Solution a;
    vector<int> numbers;
    numbers.push_back(9);
    numbers.push_back(10);
    numbers.push_back(6);
    numbers.push_back(6);
    numbers.push_back(6);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    cout << a.findMin(numbers) << endl;
    return 0;
}
