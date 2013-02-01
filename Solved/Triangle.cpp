//
//  Triangle.cpp
//  
//
//  Created by 于 卓然 on 13-1-29.
//
//

const int oo = 35566;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int l = triangle.size();
        if(!l) return 0;
        vector<int> res[2];
        res[0].push_back(triangle[0][0]);
        for(int i = 1; i < l; ++i) {
            int p = (i-1)%2, q = i%2;
            res[q].clear();
            for(int j = 0; j <= i; ++j) {
                int t = oo;
                if(j - 1 >= 0) t = min(t, res[p][j-1]);
                if(j <= i-1) t = min(t, res[p][j]);
                res[q].push_back(t + triangle[i][j]);
            }
        }
        int t = oo;
        for(int i = 0, q = (l-1)%2; i < l; ++i) t = min(t, res[q][i]);
        return t;
    }
};