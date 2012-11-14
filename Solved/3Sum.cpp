/*
 2012-11-14
 large:260 ms
 3sum
 http://en.wikipedia.org/wiki/3SUM
 */

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl
#define sp system("pause")

vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    for (int i = 0, l = num.size(); i <= l-3; ++i) {
        if(i>0) if(num[i] == num[i-1]) continue;
        int j = i+1, k = l-1;
        while(j < k){
            int sum = num[i] + num[j] + num[k];
            if (sum == 0) {
                vector<int> temp;
                temp.push_back(num[i]);
                temp.push_back(num[j]);
                temp.push_back(num[k]);
                result.push_back(temp);
//                see(i);see(j);see(k);see(sum);
                j++;
                while(num[j] == num[j-1])j++;
            } else if(sum > 0) {
                k--;
                while(num[k] == num[k+1])k--;
            } else {
                j++;
                while(num[j] == num[j-1])j++;
            }
        }
    }
    return result;
}

int main() {
    int n, in;
    vector<int> num;
    while (cin>>n) {
        num.clear();
        for (int i = 0; i < n; ++i) {
            cin>>in;
            num.push_back(in);
        }
        threeSum(num);
    }
    return 0;
}