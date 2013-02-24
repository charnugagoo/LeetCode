class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        while(n-- > 0) {
            for(int i = 0, l = res.size(); i < l; ++i) {
                res.push_back(res[l-1-i] + l ); // bug here, it is l
            }
        }
        return res;
    }
};