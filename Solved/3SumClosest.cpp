//
//  3SumCloset.cpp
//  
//
//  Created by 于 卓然 on 12-11-14.
//  100 milli secs on large data set
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

int threeSumClosest(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(num.begin(), num.end());
    int result = num[0] + num[1] + num[2], dist = abs(target - result);
    for(int i = 0, l = num.size(); i < l; ++i) {
        int t = target - num[i];
        for(int j = i+1, k = l-1; j<k; ++j) {
            while(t - num[j] - num[k] > 0 && j+1 < k) {
                if(dist > abs(target-num[j]-num[k]-num[i])) {
                    result = num[j]+num[k]+num[i];
                    dist = abs(target-result);
                }
                j++;
            }
            if(dist > abs(target-num[j]-num[k]-num[i])) {
                result = num[j]+num[k]+num[i];
                dist = abs(target-result);
            }
            if(t - num[j] - num[k] > 0)//j == k-1
                break;
            while(j<k-1 && t-num[k-1]-num[j] <= 0)// && t-num[k-1]-num[j] <= abs(t-num[j]-num[k])
                k--;
            if(dist > abs(target-num[j]-num[k]-num[i])) {
                result = num[j]+num[k]+num[i];
                dist = abs(target-result);
            }
            if(j<k-1 && dist > abs(target-num[j]-num[k]-num[i])) {
                result = num[j]+num[k]+num[i];
                dist = abs(target-result);
            }      
            see(i);see(j);see(k);
            see(dist);see(result);
            
        }
    }
    return result;
}

int main() {
    vector<int> input;
    int n, in, target;
    while (cin>>n) {
        cin>>target;
        input.clear();
        for (int i = 0; i < n; ++i) {
            cin>>in;
            input.push_back(in);
        }
        cout<<threeSumClosest(input, target)<<endl;
    }
}