const int maxn = 100000;
int sum[maxn];
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0) return 0;
        sum[0] = A[0];
        int minv = sum[0], res = sum[0];
        for(int i = 1; i < n; ++i)  {
            sum[i] = sum[i-1] + A[i];
            res = max(res, sum[i] - minv);
            res = max(res, sum[i]);
            minv = min(minv, sum[i]);
        }
        return res;
    }
};