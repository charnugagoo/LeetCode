/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
/*
 bool cmp(Interval a, Interval b) {
 if(a.start == b.start)
 return a.end < b.end;
 return a.start < b.end;
 }
 */
bool operator <(const Interval a, const Interval b) {
    if(a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}
//1 2, 3 3, 4 6,
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int l = intervals.size();
        if(l < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<Interval> res;
        for(int last_end = intervals[0].end, last_no = 0, i = 1; i < l; ++i) {
            if(last_end >= intervals[i].start) {
                last_end = max(intervals[i].end, last_end);
                if(i == l-1) {
                    Interval temp(intervals[last_no].start, last_end);
                    res.push_back(temp);
                }
            } else {
                Interval temp(intervals[last_no].start, last_end);
                res.push_back(temp);
                last_no = i;
                last_end = intervals[i].end;
                if(i == l-1) res.push_back(intervals[l-1]);
            }
        }
        return res;
    }
};