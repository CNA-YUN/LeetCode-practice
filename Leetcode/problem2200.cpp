/*2200. 找出数组中的所有 K 近邻下标
给你一个下标从 0 开始的整数数组 nums 和两个整数 key 和 k 。
K 近邻下标 是 nums 中的一个下标 i ，并满足至少存在一个下标 j 使得 |i - j| &lt;= k 且 nums[j] == key 。

以列表形式返回按 递增顺序 排序的所有 K 近邻下标。
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int len = nums.size();
        vector<int> res;
        unordered_set<int> cnt;
        for (int id = 0; id < len; id++) {
            if (nums[id] == key) {
                for (int i = id - k; i <= id + k; i++) {
                    if (i >= 0 && i < len)
                        if (cnt.find(i) == cnt.end()) {
                            cnt.insert(i);
                            res.push_back(i);
                        }
                }
            }
        }
        return res;
    }
};