//
//  InsertInterval.cpp
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//  logic!!
//  一维线段相交判断。。。。。2b....!(a.end < b.start || a.start > b.end);

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

struct Interval {
    int start, end;
    Interval(int s, int e) {start = s; end = e;}
};

class Solution {
public:
    bool inter(Interval a, Interval b) {
        return !(a.end < b.start || a.start > b.end);
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int i= 0, l = intervals.size(), ll = newInterval.start, rr = newInterval.end;
        if(!l) {
            res.push_back(newInterval);
            return res;
        }
        bool flag = false;
        for(; i < l && !inter(newInterval, intervals[i]); ++i) {
            if(intervals[i].start > newInterval.end && !flag) {
                res.push_back(newInterval);
                flag = true;
            }
            res.push_back(intervals[i]);
        }
        if(i<l) ll = min(ll, intervals[i].start);
        else {
            if(newInterval.start > intervals[l-1].end)
                res.push_back(newInterval);
            return res;
        }
        for(; i < l && inter(newInterval, intervals[i]); ++i) ;
        if(i>0) rr = max(rr, intervals[i-1].end);
        Interval temp(ll, rr);
        res.push_back(temp);
        for(; i < l; ++i) res.push_back(intervals[i]);
        return res;
    }
};

int main() {
    int n, l, r;
    vector<Interval> q;
    while(cin>>n) {
        q.clear();
        for(int i = 0; i <= n; ++i) {
            cin>>l>>r;
            Interval temp(l, r);
            if(i == n) {
                q = insert(q, temp);
                break;
            }
            q.push_back(temp);
        }
        for(int i = 0; i < q.size(); ++i)
            cout<<q[i].start<<" "<<q[i].end<<endl;
    }
    return 0;
}




