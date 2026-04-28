/*2033. 获取单值网格的最小操作数
给你一个大小为 m x n 的二维整数网格 grid 和一个整数 x 。
每一次操作，你可以对 grid 中的任一元素 加 x 或 减 x 。

单值网格 是全部元素都相等的网格。

返回使网格化为单值网格所需的 最小 操作数。如果不能，返回 -1 。
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
    int minOperations(vector<vector<int>>& grid, int x) {
        int k = grid.size() * grid[0].size();
        vector<int>num;
        num.reserve(k);
        int target = grid[0][0] % x;
        for (auto& i : grid) {
            for (auto& j : i) {
                if (j % x != target)
                    return -1;
                num.push_back(j);
            }
        }
        sort(num.begin(), num.end());

        int mid = num[k / 2];
        int cnt = 0;
        for (auto& i : num) {
            cnt += abs(i - mid);
        }
        return cnt/x;
    }
};