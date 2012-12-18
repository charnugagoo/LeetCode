//
//  LongestCommonPrefix.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
//
// almost no bug....


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(!strs.size())
            return "";
        char res[1000];
        int i = 0;
        for( ; ; ++i) {
            bool flag = true;
            for(int j = 0, l = strs.size(); j < l; ++j) {
                if(strs[j].size() <= i) {
                    flag = false;
                    break;
                }
                if(j > 0 && strs[j][i] != strs[j-1][i]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                res[i] = strs[0][i];
            else
                break;
        }
        res[i] = '\0';
        string temp(res);
        return temp;
    }
};