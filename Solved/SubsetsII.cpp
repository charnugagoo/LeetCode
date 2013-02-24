//
//  SubsetsII.cpp
//  
//
//  Created by 于 卓然 on 13-2-22.
//
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res, temp;
        vector<int> t;
        res.push_back(t);
        if(!S.size()) {
            return res;
        }
        
        sort(S.begin(), S.end());
        
        for(int i = 0, j, l = S.size(); i < l; ) { // no ++i!!!!!!!! bug here
            for(j = i; S[j] == S[i] && j < l; ++j); //[i...j)
            temp.clear();
            for(int k = 0; k <= j-i; ++k) { //add k S[i] at the end
                for(int p = 0; p < res.size(); ++p) {
                    if(k > 0) res[p].push_back(S[i]);
                    temp.push_back(res[p]);
                }
            }
            i = j;
            res = temp;
        }
        return res;
    }
};

int main() {
    vector<int> t(2); t[0] = 0; t[1] = 1;
    vector<vector<int> > res;
    Solution a;
    res = a.subsetsWithDup(t);
    see(res.size());
    for(int i = 0; i < res.size(); ++i) {
        see(res[i].size());
        for(int j = 0; j < res[i].size(); ++j) {
            see(res[i][j]);
        }
    }
    return 0;
}