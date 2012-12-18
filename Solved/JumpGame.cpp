//
//  JumpGame.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
// be careful about the >=....

class Solution {
public:
    bool canJump(int A[], int n) {
        int m = 0;
        for(int i = 0; i < n && i <= m; ++i) {
            m = max(m, i+A[i]);
        }
        if(m >= n-1) return true;
        return false;
    }
};