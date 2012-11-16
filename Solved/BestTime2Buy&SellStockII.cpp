//
//  BestTime2Buy&SellStockII.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//
//  I blocked for 10 min here....My brain....
//  this program just find the longest increasing sub-sequences
//  40ms for large, 2 mistakes

#include <stdio.h>

int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(prices.size()<=1) return 0;
    int res = 0, start = prices[0];
    for(int i = 1, l = prices.size(); i < l; ++i) if(prices[i]<prices[i-1]){
        res += prices[i-1] - start;
        start = prices[i];
    }
    return res += prices[prices.size()-1] - start;
}