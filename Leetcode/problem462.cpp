/*462. 最小操作次数使数组元素相等 II
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最小操作数。

在一次操作中，你可以使数组中的一个元素加 1 或者减 1 。

测试用例经过设计以使答案在 32 位 整数范围内。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[len / 2];
        for (auto& num : nums) {
            cnt += abs(num - mid);
        }
        return cnt;
    }
};