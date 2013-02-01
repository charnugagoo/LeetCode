//
//  MaximalRectangle.cpp
//  
//
//  Created by 于 卓然 on 13-1-8.
//
//  终于搞完了，花了一下午时间。假期状态巨水无比

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 1000;
int dp[maxn][maxn];
int l[maxn], r[maxn];

int maximalRectangle(vector<vector<char> > &matrix) {
    memset(dp, 0, sizeof(dp));
    int i, j, k, m = matrix.size();
    if(!m) return 0;
    int n = matrix[0].size();
    if(!n) return 0;
    for(j = 0; j < n; ++j) {
        for(i = 0; i < m; ++i) {
            if(matrix[i][j] == '1') dp[i][j] = 1;
            if(i > 0 && matrix[i][j] == '1') dp[i][j] += dp[i-1][j];
        }
    }

    int res = 0;
    for(i = 0; i < m; ++i) {
        int p, q;
        l[0] = 0;
        res = max(res, dp[i][0]);
        for(p = 1; p < n; ++p){
            if(dp[i][p-1] < dp[i][p])
                l[p] = p;
            else {
                for(q = p - 1; dp[i][l[q]] >= dp[i][p];)
                    if(l[q] == q)
                        if(q > 0 && dp[i][q-1] >= dp[i][p])
                            q = q - 1;
                        else
                            break;
                    else
                        q = l[q];
                l[p] = q;
            }
        }
        r[n-1] = n-1;
        res = max(res, dp[i][n-1]);
        for(p = n-2; p >= 0; --p){
            if(dp[i][p+1] < dp[i][p])
                r[p] = p;
            else {
                for(q = p + 1; dp[i][r[q]] >= dp[i][q];)
                    if(r[q] == q)
                        if(q < n-1 && dp[i][q+1] >= dp[i][p])
                            q = q + 1;
                        else
                            break;
                    else
                        q = r[q];
                r[p] = q;
            }
            res = max(res, (r[p] - l[p] + 1) * dp[i][p]);
        }
    }
    return res;
}

//010100
//001101
//
//int main() {
//    vector<vector<char> > input;
//    vector<char> t;
//    t.push_back('0');
//    t.push_back('1');
//    t.push_back('0');
//    t.push_back('1');
////    t.push_back('1');
//    t.push_back('0');
//    t.push_back('0');
//    input.push_back(t);
//    t.clear();
////    t.push_back('1');
//    t.push_back('0');
//    t.push_back('0');
//    t.push_back('1');
////    input.push_back(t);
////    t.clear();
//    t.push_back('1');
////    t.push_back('1');
////    t.push_back('1');
////    t.push_back('1');
////    input.push_back(t);
//////    t[0] = '1';
//    t.push_back('0');
//    t.push_back('1');
////    t.push_back('0');
////    t.push_back('1');
////    t.push_back('0');
////    t.push_back('1');
//    input.push_back(t);
////    t.clear();
////    t.push_back('0');
////    t.push_back('1');
////    t.push_back('1');
////    t.push_back('1');
////    t.push_back('0');
////    t.push_back('0');
////    t.push_back('1');
////    t.push_back('0');
////    input.push_back(t);
//    cout<<maximalRectangle(input)<<endl;
//}
