//
//  LengthOfLastWord.cpp
//  
//
//  Created by 于 卓然 on 12-12-14.
//
//  Hi, man!!  Are you kiding me? How did you bugs in this program.....
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt = 0;
        for(int i = 0, l = strlen(s); i < l; ++i) {
            if(i > 0 && s[i] != ' ' && s[i-1] == ' ') cnt = 1;
            else if(s[i] != ' ') cnt++;
        }
        return cnt;
    }
};