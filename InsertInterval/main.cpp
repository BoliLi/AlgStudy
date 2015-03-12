#include <iostream>
#include <vector>
#include <algorithm>
/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].*/
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int start = 0, foundS = 0, foundE = 0;

        for(Interval iv : intervals) {
            if(foundS) {
                if(iv.end >= newInterval.end) {
                    if(iv.start > newInterval.end) {
                        Interval tmp(start, newInterval.end);
                        ret.push_back(tmp);
                        ret.push_back(iv);
                    } else {
                        Interval tmp(start, iv.end);
                        ret.push_back(tmp);
                    }
                    foundS = 0;
                    foundE = 1;
                }
            } else if(foundE) {
                ret.push_back(iv);
            } else {
                if(iv.end >= newInterval.start) {
                    start = min(iv.start, newInterval.start);
                    foundS = 1;
                } else {
                    ret.push_back(iv);
                }
            }
        }

        for(Interval iv : ret) {
            cout << "[" << iv.start << ", " << iv.end << "]" << endl;
        }
        return ret;
    }
};

int main()
{
    Solution a;
    vector<Interval> intervals;

    Interval it(1, 2);
    intervals.push_back(it);
    it.start = 3;
    it.end = 5;
    intervals.push_back(it);
    it.start = 6;
    it.end = 7;
    intervals.push_back(it);
    it.start = 8;
    it.end = 10;
    intervals.push_back(it);
    it.start = 12;
    it.end = 16;
    intervals.push_back(it);
    Interval iv(5, 9);
    a.insert(intervals, iv);
    cout << "Hello world!" << endl;
    return 0;
}
