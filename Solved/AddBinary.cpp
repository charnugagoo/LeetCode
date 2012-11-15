//
//  AddBinary.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//  12ms for large
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl
#define sp system("pause")

string addBinary(string a, string b) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(a.length() < b.length()){
        string c(a);
        a = b;
        b = c;
    }
    string res(a);//see(res);
    for (int i = 0, up = 0, l1 = a.length(), l2 = b.length(); i < l1; ++i) {
        if(i < l2) {
            int sum = up+(a[l1-i-1]-'0')+(b[l2-i-1]-'0');
            if(sum>=2) up = 1, sum -= 2;
            else up = 0;
            res[l1-i-1] = (char)(sum + '0');
        } else {
            int sum = up+(a[l1-i-1]-'0');
            if(sum>=2) up = 1, sum -= 2;
            else up = 0;
            res[l1-i-1] = (char)(sum + '0');
        }
        if(i == l1-1 && up != 0)
            res.insert(0, "1");
        //see(res);
    }
    return res;
}

int main() {
    string a, b;
    cin>>a>>b;
    cout<<addBinary(a, b)<<endl;
    return 0;
}