//
//  GenerateParenthese.cpp
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//  it should be a[par] = '(' not a[par+1] = '('
// only this bug...

#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

int N;
char a[200];
vector<string> res;
//number of Parenthese, number of (, 
void dfs(int par, int lp) {
    if(lp == N) {
        for(int i = par; i < 2*N; ++i) a[i] = ')';
        a[2*N] = '\0';
//        printf("%s\n", a);
        string temp(a);
        res.push_back(temp);
        return;
    }
    //dfs lp
    a[par] = '(';
    dfs(par+1, lp+1);
    if(lp > par - lp) {
        //dfs rp
        a[par] = ')';
        dfs(par+1, lp);
    }
    return ;
}

vector<string> generateParenthesis(int n) {
    N = n;
    res.clear();
    dfs(0, 0);
    return res;
}

int main() {
    int n;
    while(cin>>n) {
        generateParenthesis(n);
        for(int i = 0; i < res.size(); ++i)
            cout<<res[i]<<endl;
    }
}