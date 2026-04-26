/*
2089. 找出数组排序后的目标下标
给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。

目标下标 是一个满足 nums[i] == target 的下标 i 。

将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。
如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。
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
	int low_bound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return left;
	}
	vector<int> targetIndices(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int start = low_bound(nums, target);
		if (start == nums.size() || nums[start] != target) {
			return {};
		}
		vector<int>res;
		int end = low_bound(nums, target + 1);
		for (int i = start;i < end;i++) {
			res.push_back(i);
		}
		return res;

	}
};