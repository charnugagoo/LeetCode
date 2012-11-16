//
//  Anagrams.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//  unsolved, for I want algorithm without hash.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

vector<string> anagrams(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
}

int main() {
    int n;
    vector<string> in;
    while(cin>>n) {
        for(int i = 0; i < n; ++i) {
            string temp;
            cin>>temp;
            in.push_back(in);
        }
        in = anagrams(in);
        for(int i = 0, l = in.size(); i < l; ++i) {
            cout<<in[i]<<endl;
        }
    }
    return 0;
}