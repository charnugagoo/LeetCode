//
//  EditDistance.cpp
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//

#include <stdio.h>
#include <iostream>
#include<string.h>

using namespace std;
#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 500;

class Solution {
public:
    int dp[maxn][maxn];
    string w1, w2;
    int val(int i, int j) {
//        see(i);see(j);
        if(i<0 && j<0) return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]>=0)
            return dp[i][j];
        dp[i][j] = maxn;
        dp[i][j] = min(dp[i][j], val(i-1, j) + 1);
        dp[i][j] = min(dp[i][j], val(i, j-1) + 1);
//        see(w1[i]);see(w2[j]);see(val(i-1, j-1));
        if(w1[i] == w2[j])
            dp[i][j] = min(dp[i][j], val(i-1, j-1));
        else
            dp[i][j] = min(dp[i][j], val(i-1, j-1) + 1);
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        w1 = word1, w2 = word2;
        //为什么tmd memset能超时啊？魂淡！！！！
        //数组要1000就超时啊！！！
        memset(dp, -1, sizeof(dp));
        return val(word1.length()-1, word2.length()-1);
    }
};

int main() {
    string w1, w2;
    Solution p;
    while(cin>>w1>>w2) {
        cout<<p.minDistance(w1, w2)<<endl;
    }
    return 0;
}


