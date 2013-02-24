//some bugs ToT

class Solution {
public:
    int numDecodings(string s) {
        int a[3], l = s.length();
        if(!l) return 0;
        if(s[0] == '0') return 0;
        a[0] = 1;
        for(int i = 1; i < l; ++i) {
            if(s[i] == '0')
                a[i%3] = 0;
            else
                a[i%3] = a[(i-1)%3];
            int t = 10*(s[i-1] - '0') + s[i] - '0';
            if( 1 <= t && t <= 26 && s[i-1] != '0')
                if(i > 1)
                    a[i%3] += a[(i-2)%3];
                else
                    a[1] += 1;
        }
        return a[(l-1)%3];
    }
};