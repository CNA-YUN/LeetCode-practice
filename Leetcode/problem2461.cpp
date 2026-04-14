/*2461. 长度为 K 子数组中的最大和
给你一个整数数组 nums 和一个整数 k 。
请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：
 * 子数组的长度是 k，且
 * 子数组中的所有元素 各不相同 。
返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。
子数组 是数组中一段连续非空的元素序列。
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		long long sum = 0, n = nums.size();
		long long res = 0;

		for (int i = 0; i < n; i++) {
			// 进入窗口
			sum += nums[i];
			map[nums[i]]++; // 初始值为0，然后加1

			// 子数组左边界
			if (i - k + 1 < 0)
				continue; // 窗口大小小于k

			// 更新答案
			if (map.size() == k) {
				res = sum > res ? sum : res;
			}
			// 离开窗口

			if (map[nums[i - k + 1]] == 1)
				map.erase(nums[i - k + 1]);
			else {
				map[nums[i - k + 1]]--;
			}
			sum -= nums[i - k + 1];
		}
		return res;
	}
};