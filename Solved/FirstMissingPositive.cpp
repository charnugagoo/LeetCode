//
//  FirstMissingPositive.cpp
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//
// Orz I read others' code yet..

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; ++i) if(A[i] > 0){
            while(A[i] > 0 && A[i] <= n && A[i] != i+1 && A[i] != A[A[i]-1])
                swap(A[i], A[A[i]-1]);
        }
        for(int i = 0; i < n; ++i)
            if(A[i] != i+1)
                return i+1;
        return n+1;
    }
};