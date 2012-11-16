//
//  ClimbingStairs.cpp
//  
//
//  Created by 于 卓然 on 12-11-16.
//
//  8ms for large
//  这tmd都能让我写出bug？。、。。初始条件给错了。。。

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1) return 1;
        int a = 1, b = 1, c;
        for(int i = 0; i <= n-2; ++i) {
            c = a + b;
            if(i == n-2) return c;
            else {
                a = b;
                b = c;
            }
        }
    }
};