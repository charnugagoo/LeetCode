//
//  BestTime2Buy&SellStock.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//  52ms for large
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(prices.size() == 0) return 0;
    int res = 0, mv = prices[0];
    for(int i = 0, l = prices.size(); i < l; ++i) {
        mv = min(mv, prices[i]);
        res = max(res, prices[i]-mv);
    }
    return res;
}

