//
//  ContainerWithMostWater.cpp
//  
//
//  Created by 于 卓然 on 12-12-12.
//
//
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size()-1;
        int ans = (j-i) * min(height[i], height[j]);
        while(i < j) {
            if(height[j] < height[i]) j--;
            else i++;
            ans = max( ans, (j-i)*min(height[i], height[j]));
        }
        return ans;
    }
};