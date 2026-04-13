#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res=nums.size();
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == target) {
                res = abs(i - start) < res ? abs(i - start) : res;
            }
        }
        return res;
    }
};