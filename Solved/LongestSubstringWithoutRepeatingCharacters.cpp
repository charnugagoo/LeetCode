//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
//  naive? two pointers



    bool vis[26];
    int lengthOfLongestSubstring(string s) {
        memset(vis, false, sizeof(vis));
        int res = 0;
        for(int i = 0, j = 0, l = s.size(); i < l && j < l; ){
            printf("%d %d\n", i, j);
            bool flag = false;
            for(; j < l; ++j)
                if(!vis[s[j] - 'a'])
                    vis[s[j] - 'a'] = true;
                else {
                    flag = true;
                    break;
                }
            res = max(res, j - i);
            if(!flag)
                break;
            for(; s[i]!=s[j]; ++i) {
                vis[s[i] - 'a'] = false;
            }
            i++;
            j++;
        }
        return res;
    }
