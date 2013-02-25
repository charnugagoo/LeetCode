//two bugs

const int maxn = 100;
class Solution {
public:
    int dp[maxn][maxn][maxn];
    string ss1, ss2;
    int find(int i, int j, int k) {
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        if(k == 1) {
            dp[i][j][k] = (ss1[i] == ss2[j]);
        } else {
            dp[i][j][k] = 0;
            for(int l = 1; l <= k-1; ++l) {
                //it should be find() not dp[][][]
                if(find(i, j, l) && find(i+l, j+l, k-l)) dp[i][j][k] = 1;
                else if(find(i, j+k-l, l) && find(i+l, j, k-l)) dp[i][j][k] = 1;//it should be i+l,j,k-l not i+l,j+l,k-l
            }
        }
        return dp[i][j][k];
        
    }
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        ss1 = s1, ss2 = s2;
        if(s1.length() != s2.length())
            return false;
        return 1==find(0, 0, s1.length());
    }
};