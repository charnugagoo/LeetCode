//
//  Count&Saycpp.cpp
//  
//
//  Created by 于 卓然 on 12-12-12.
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

class Solution {
public:
    char a[5000], b[5000];
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a[0] = '1'; a[1] = '\0';
        for(int t = 1, w; t < n; ++t) {
            w = 0;
            for(int i = 0, j = 0, l = strlen(a); i < l;) {
                for(j = i; j < l && a[j] == a[i]; ++j) ;
                //see(t);see(i);see(j);
                b[w++] = j - i + '0';
                b[w++] = a[i];
                i = j;
            }
            b[w] = '\0';
            for(int i = 0, l = strlen(b) + 1; i < l; ++i) a[i] = b[i];
        }
        string res(a);
        return res;
    }
};

int main() {
    Solution a;
    int n;
    while(cin>>n) {
        cout<<a.countAndSay(n)<<endl;
    }
    return 0;
}
