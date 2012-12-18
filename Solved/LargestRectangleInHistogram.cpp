//
//  LargestRectangleInHistogram.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
/*
让你明白，什么交一大波bug袭来。。。。

没想出好的证明l[l[i]]类似写法的复杂度证明。。就写stack的了。。。结果好多bug啊。。。
 
具体做法是：
 对于每一个block i，计算h[i] * (r[i] - l[i] + 1), 其中l[i]是这个集合中的最小值 {x|h[x] <= h[i]}
 
 用stack维护一个队列，保持队列中位单调递增的。如图

 
               |||||
        ||||||||||||
    ||||||||||||||||
||||||||||||||||||||
 
 扫描的时候想着这个图，中间长的部分截掉。
 
 找l[i]时，不断弹出stack，直到找到一个比h[i]小，那么l[i]就是这个block+1。再把当前的i放进stack里。

*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 100000;
int l[maxn], r[maxn], s[maxn], st;

    int largestRectangleArea(vector<int> &height) {
        l[0] = 0;
        st = 0;
        int i, len = height.size();
        if(!len) return 0;
        for(i = 0; i < len; ++i) {
            if(st == 0 || height[s[st-1]] < height[i]) {
                s[st++] = i;
                l[i] = i;
                continue;
            }
            while(st > 0 && height[s[st-1]] >= height[i]) {
                st--;
            }
            if(st == 0)
                l[i] = 0;
            else
                l[i] = s[st-1]+1;
            s[st++] = i;
        }
        //
        r[0] = 0;
        st = 0;
        for(i = len-1; i >= 0; --i) {
            if(st == 0 || height[s[st-1]] < height[i]) {
                s[st++] = i;
                r[i] = i;
                continue;
            }
            while(st > 0 && height[s[st-1]] >= height[i]) {
                st--;
            }
            if(st == 0)
                r[i] = len-1;
            else
                r[i] = s[st-1]-1;
            s[st++] = i;
        }
        //
        int mx = -1;
        for(i = 0; i < len; ++i) {
            printf("%d-%d: %d, %d --- %d\n", i, height[i], l[i], r[i], (r[i] - l[i] + 1) * height[i]);
            mx = max(mx, (r[i] - l[i] + 1) * height[i]);
        }
        return mx;
    }

int main() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(3);
    see(largestRectangleArea(a));
}