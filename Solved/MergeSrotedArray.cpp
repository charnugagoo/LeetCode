//two bugs
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int l = m + n - 1, i = m - 1, j = n-1; j >= 0; l--) {//it is j>=0 not j>0
            if(i < 0 || A[i] < B[j]) A[l] = B[j--];//it is < not >
            else if(j < 0 || A[i] >= B[j]) A[l] = A[i--];
        }
    }
};