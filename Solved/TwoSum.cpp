//
//  TwoSum.cpp
//  
//
//  Created by 于 卓然 on 13-2-8.
//
//  no bug


struct Node
{
    int val;
    int index;
    Node(){}
    Node(int v, int idx):val(v), index(idx){}
};

bool cmp(const Node &lhs, const Node &rhs) {
    return lhs.val < rhs.val;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> a;
        for(int i = 0; i < numbers.size(); i++)
            a.push_back(Node(numbers[i], i + 1));
        sort(a.begin(), a.end(), cmp);
        int i = 0, j = a.size() - 1;
        for(; i < j && a[i].val + a[j].val != target; ) {
            while(a[i].val + a[j].val > target) --j;
            while(a[i].val + a[j].val < target) ++i;
        }
        if(a[i].val + a[j].val == target) {
            vector<int> result(2);
            result[0] = min(a[i].index, a[j].index);
            result[1] = max(a[i].index, a[j].index);
            return result;
        }
    }
};
