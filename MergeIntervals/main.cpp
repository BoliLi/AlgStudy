#include <iostream>
#include <vector>
#include <algorithm>
/*Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].*/
using namespace std;
// 注意sort的用法
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), compareInterval);

        Interval res = intervals[0];
        for(Interval it : intervals) {
            if(res.end > it.start)
                res.end = it.end;
            else {
                ret.push_back(res);
                res = it;
            }
        }
        ret.push_back(res); //最后一个集合别忘了

        for(Interval &it : ret) {
            cout << "[" << it.start << " " << it.end << "] ";
        }
        return ret;
    }
};

int main()
{
    vector<Interval> intervals;
    Solution a;

    Interval it(2, 6);
    intervals.push_back(it);
    it.start = 8;
    it.end = 10;
    intervals.push_back(it);
    it.start = 15;
    it.end = 18;
    intervals.push_back(it);
    it.start = 1;
    it.end = 3;
    intervals.push_back(it);

    a.merge(intervals);
    cout << "Hello world!" << endl;
    return 0;
}
