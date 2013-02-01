//
//  MedianofTwoSortedArray.cpp
//  
//
//  Created by 于 卓然 on 13-1-23.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 100;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int l1 = 0, r1 = m-1, p1, t1;
    while(l1 <= r1) {
        p1 = (l1 + r1) / 2;
        
        int l2 = 0, r2 = n-1, p2, t2 = p1;
        while(l2 <= r2) {
            if()
        }
        
        if(!t1) {
            return
        } else if(t1 > 0) {
            l1 = p1 + 1;
        } else {
            r1 = p1 - 1;
        }
    }
}
