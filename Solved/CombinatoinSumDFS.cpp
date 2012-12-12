//
//  CombinatoinSumDFS.cpp
//  
//
//  Created by 于 卓然 on 12-11-17.
//
//

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> can;
vector<vector<int> > dfs(int cnt, int now, int target, vector<int>) {
    
    if(cnt>=can.size()) return NULL;
    for(j = 0; j+now<=target; j+= cam[cnt]) {
        if(j+now == target) return
        dfs(cnt+1, j+now, target);
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    can = candidates;
    vector<int> par;
    return dfs(0, 0, target, par);
}

int main() {
    int n, target, in;
    while(cin>>n>>target) {
        vector<int> input;
        for(int i = 0; i < n; ++i){
            cin>>in;
            input.push_back(in);
            combinationSum(input);
        }
    }
    return 0;
}