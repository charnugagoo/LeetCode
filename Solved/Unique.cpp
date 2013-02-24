//this should be catalan number, but the test set is not too big

class Solution {
public:
    int numTrees(int n) {
        if(!n) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int res = 0;
        for(int i = 0; i < n; ++i) res += numTrees(i)*numTrees(n - i - 1);
        return res;
    }
};