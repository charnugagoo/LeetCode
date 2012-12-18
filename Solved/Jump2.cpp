//
//  Jump2.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
//  logic...

#include <stdio.h>
#include <iostream>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

int jump(int A[], int n) {
    if(n <= 1) return 0;
    int i = 0, step = 0;
    while(i <= n-2) {
        if(A[i] == 0) break;
        if(i + A[i] >= n-1) { i += A[i]; break;}
        int maxl = i, maxi = i, j;
        for(j = i+1; j <= A[i] + i && j < n; ++j) {
            if(maxl <= A[j] + j) {
                maxl = A[j] + j;
                maxi = j;
            }
        }
        i = maxi;
    }
    if(i >= n-1) return step;
    else return -1;
}

int main() {
    int n, a[10];
    while(cin>>n) {
        for(int i = 0; i < n; ++i) cin>>a[i];
        cout<<jump(a, n)<<endl;
    }
}