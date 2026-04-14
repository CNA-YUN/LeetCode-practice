/*
2841. 几乎唯一子数组的最大和
给你一个整数数组 nums 和两个正整数 m 和 k 。
请你返回 nums 中长度为 k 的 几乎唯一 子数组的 最大和 ，如果不存在几乎唯一子数组，请你返回 0 。
如果 nums 的一个子数组有至少 m 个互不相同的元素，我们称它是 几乎唯一 子数组。
子数组指的是一个数组中一段连续 非空 的元素序列。
*/
#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
	long long maxSum(vector<int>& nums, int m, int k) {
		unordered_map<long long, int>map;
		set<long long>element;
		long long sum = 0;
		long long res = INT_MIN;
		int n = nums.size();
		bool flag = false;

		for (int i = 0;i < n;i++) {
			if (map.find(nums[i]) == map.end()) { // 同一元素的数量 存储在 map 中

				map[nums[i]] = 1;
			}
			else {
				map[nums[i]]++;
			}
			element.insert(nums[i]); // 将 进入子数组的元素 插入集合 element

			sum += nums[i];

			if (i >= k - 1) {// 若子数组的长度大于等于k
				if (i > k - 1) {// 若左边界已越过下标0
					sum -= nums[i - k]; // 将 出子数组的元素 从sum中减去
					map[nums[i - k]]--;// 将 出子数组的元素 从map中减1
					if (map[nums[i - k]] < 1) {// 判断 出子数组的元素 是否在 新子数组 中
						element.erase(nums[i - k]);// 从集合中删除 出子数组的元素
					}
				}
				if (element.size() >= m) {// 集合 element 的长度 即为子数组中 互不相同的元素个数
					flag = true;
					res = sum > res ? sum : res;

				}
			}
		}
		return flag ? res : 0;
	}
};