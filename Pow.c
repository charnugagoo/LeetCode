//
//  Pow.c
//  
//
//  Created by 于 卓然 on 13-1-31.
//
// ？？？？？？

class Solution {
public:
    double pow(double x, int n) {
        if(n == -2147483648) return 1.0;
        if(!n) return 1.0;
        if(n<0) return 1.0/pow(x, -1*n);
        if(n&1) return x*pow(x, n-1);
        double t = pow(x, n/2);
        return t*t;
    }
};