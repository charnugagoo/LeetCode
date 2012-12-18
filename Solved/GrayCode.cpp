//
//  GrayCode.cpp
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

vector<int> grayCode(int n) {
    //太2了。这题出的
    if(n == 0) {vector<int> a(1,0); return a;}
    if(n == 1) {
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(1);
        return temp;
    }
    vector<int> temp = grayCode(n-1);
    vector<int> res(1<<n);
    for(int i = 0, l = 1<<(n-1); i < l; ++i) {
        res[i] = temp[i];
        see(res[i]);
    }
    for(int i = 1<<(n-1), l = 1<<n; i < l; ++i) {
        res[i] = temp[l - i - 1] | (1<<(n-1));
        see(res[i]);
    }
    return res;
}

int main() {
    int n;
    while(cin>>n)
        grayCode(n);
    return 0;
}