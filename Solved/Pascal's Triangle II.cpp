//
//  Pascal's Triangle II.cpp
//  
//
//  Created by 于 卓然 on 13-1-29.
//
// no bugs, hahahaha

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res[2];
        res[0].push_back(1);
        for(int i = 1; i <= rowIndex; ++i) {
            int p = (i-1)%2, q = i%2;
            res[q].clear();
            res[q].push_back(1);
            for(int j = 1; j < i; ++j) {
                res[q].push_back( res[p][j-1] + res[p][j]);
            }
            res[q].push_back(1);
        }
        return res[rowIndex%2];
    }
};