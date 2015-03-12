#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        return getMin(num, 0, num.size() - 1);
    }
private:
    int getMin(vector<int> &num, int beg, int end) {
        if(beg == end - 1)
            return min(num[beg], num[end]);
        int med = beg + (end - beg) / 2;
        if(num[beg] > num[med])
            return getMin(num, beg, med);
        else if(num[med] > num[end])
            return getMin(num, med, end);
        else
            return min(getMin(num, beg, med), getMin(num, med, end));
    }
};

int main()
{
    Solution a;
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    cout << a.findMin(numbers) << endl;
    return 0;
}
