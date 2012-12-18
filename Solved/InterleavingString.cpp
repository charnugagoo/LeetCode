//
//  File.c
//  
//
//  Created by 于 卓然 on 12-12-14.
//
// nearly no bugs...

const int maxn = 500;
class Solution {
public:
    int dp[maxn][maxn];
    string x1, x2, x3;
    bool val(int i, int j) {
        if(dp[i][j]>=0) return dp[i][j];
        dp[i][j] = 0;
        if(i>0)
            if(val(i-1, j) && x1[i-1] == x3[i+j-1])
                dp[i][j] = 1;
        if(j>0)
            if(val(i, j-1) && x2[j-1] == x3[i+j-1])
                dp[i][j] = 1;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        if(s1.size() + s2.size() != s3.size()) return false;
        x1 = s1; x2 = s2; x3 = s3;
        dp[0][0] = 1;
        return val(s1.size(), s2.size());
    }
};