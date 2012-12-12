//
//  ImplementStrStr.cpp
//  
//  This KMP is important
//  Created by 于 卓然 on 12-12-11.
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

const int maxn = 100000;
int p[maxn];
//int kmp[maxn];
char *strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i, j = -1, l1 = strlen(haystack), l2 = strlen(needle);
    //.......wu yu le
    if(l2 == 0) return haystack;
    p[0] = -1;
    for(i = 1; i < l2; ++i) {
        while(j >= 0 && needle[j+1] != needle[i]) j = p[j];
        if(needle[j+1] == needle[i]) j++;
        p[i] = j;
    }
    
    j = -1;
    for(i = 0; i < l1; ++i) {
        while(j >= 0 && needle[j+1] != haystack[i]) j = p[j];
        if(needle[j+1] == haystack[i]) j++;
        //kmp[i] = j+1;
        if(j == l2-1) {
            return haystack+i-j;
        }
    }
    return NULL;
}

char a[maxn], b[maxn];

int main() {
    while(scanf("%s%s", a, b) != EOF) {
        char* p = strStr(a, b);
        printf("%s\n", p);
    }
    return 0;
}