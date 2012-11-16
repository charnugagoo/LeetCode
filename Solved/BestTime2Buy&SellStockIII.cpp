//
//  BestTime2Buy&SellStockIII.c
//  
//
//  Created by 于 卓然 on 12-11-16.
//
//  156ms for large
//  O(n) algorithm
//  max_sub size must be larger than 1e5
//  if max_sub size is 1e6, the runtime is 1286ms....why???
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

int max_sub[100000];


int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(prices.size() <= 1) return 0;

    //cal max_sub[i] is the best result buy and sell once after day i
    //cal max_subb[i] is the best result but at day i and sell after day i, once
    memset(max_sub, 0, sizeof(max_sub));
    int mx = prices[prices.size()-1];
    max_sub[prices.size()-1] = 0;
    for(int i = prices.size()-2; i >= 0; --i) {
        mx = max(mx, prices[i]);
        max_sub[i] = max(max_sub[i+1], mx - prices[i]);
//        see(i);see(max_sub[i]);
    }
    
    int res = 0, mv = prices[0];
    for(int i = 0, l = prices.size(); i <= l-2; ++i) {
        mv = min(mv, prices[i]);
        res = max(res, prices[i]-mv + max_sub[i]);
//        see(i);see(prices[i]-mv);
//        see(res);
    }
    return res;
}

int main() {
    int n, in;
    while(cin>>n) {
        vector<int> ins;
        for(int i = 0; i < n; ++i) {
            cin>>in;
            ins.push_back(in);
        }
        cout<<maxProfit(ins)<<endl;
    }
}