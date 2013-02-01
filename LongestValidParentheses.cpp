//
//  LongestValidParentheses.cpp
//  
//
//  Created by 于 卓然 on 12-12-21.
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 1000;
int pt[maxn], t, ll[maxn];
char st[maxn];
int longestValidParentheses(string s) {
    int l = s.size(), ans = 0;
    if(l < 2) return 0;
    t = 0;
    st[t] = s[0];
    pt[t++] = 0;
    for(int i = 1; i < l; ++i) {
        if(s[i] == '(' || (t > 0 && s[i] == ')' && st[t-1] == ')')) {
            st[t] = s[i];
            pt[t] = i;
            t++;
        } else if(t > 0){
            ans = max(ans, i - pt[t-1] + 1);
            t--;
        }
        see(i);
    }
    see(ans);
    return ans;
}

int main() {
    string query = "((()()()))";
    longestValidParentheses(query);
    return 0;
}
