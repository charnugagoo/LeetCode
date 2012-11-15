//
//  4sum.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//  344ms large
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

vector<vector<int> > fourSum(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(num.begin(), num.end());
    vector<vector<int> > result;
    for (int i = 0, l = num.size(); i <= l-4; ++i) {//see(i);
        if(i>0) if(num[i] == num[i-1]) continue;
        for (int j = i+1, l = num.size(); j <= l-3; ++j) {//see(j);
            if(j>i+1) if(num[j] == num[j-1]) continue;
            int a = j+1, b = l-1;
            while(a < b) {
                int sum = num[i] + num[j] + num[a] + num[b];
                if(sum == target) {
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(num[a]);
                    temp.push_back(num[b]);
                    result.push_back(temp);
                    //see(num[i]);see(num[j]);see(num[a]);see(num[b]);
                    a++;
                    while(num[a] == num[a-1] && a < b)a++;
                } else if(sum > target) {
                    b--;
                    while(num[b] == num[b+1] && a < b)b--;
                }else {//sum < target
                    a++;
                    while(num[a] == num[a-1] && a < b)a++;
                    
                }
            }
        }
    }
    //if no return result, there will be "malloc: *** error"
    return result;
}

int main() {
    int n, in,t;
    vector<int> num;
    while (cin>>n>>t) {
        num.clear();
        for (int i = 0; i < n; ++i) {
            cin>>in;
            num.push_back(in);
        }
        fourSum(num,t);
    }
    return 0;
}