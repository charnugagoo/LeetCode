class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0, j = -1, t;
        for(; i < n; ++i) {
            if(j >= 0 || A[i] != A[j]) {
                t = 0;
                A[++j] = A[i];
            } else {
                ++j;
            }
        }
        return j+1;
    }
};