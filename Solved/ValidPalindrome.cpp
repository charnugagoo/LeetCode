//
//  ValidPalindrome.cpp
//  
//
//  Created by 于 卓然 on 13-1-31.
//
//
class Solution {
public:
    bool isAlphanumeric(char &c) {
        if(c >= 'A' && c <= 'Z') c += 32;
        else if(c >= '0' && c <= '9' || c >= 'a' && c <= 'z') return true;
        else return false;
        
        return true;
    }
    bool isPalindrome(string s) {
        int j = s.length() - 1, i = 0;
        while(i < j) {
            if(!isAlphanumeric(s[i])) ++i;
            else if(!isAlphanumeric(s[j])) --j;
            else if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};