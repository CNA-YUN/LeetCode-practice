//leetcode 3741.三个相等元素之间的最小距离 II
/*
* 首先定义后继数组 next，设 next[i] 记录了 nums[i] 在 nums 中下一次出现的位置。
倒序遍历 nums，配合哈希表记录 nums[i] 在倒序遍历中最近一次出现的位置，即可求出 next 数组。
随后遍历 nums，借助 next 数组，我们可以在 O(1) 的时间内求出与 nums[i] 值相同的两个相邻的后继元素，
计算距离并更新答案即可。

作者：力扣官方题解
链接：https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/solutions/3941271/san-ge-xiang-deng-yuan-su-zhi-jian-de-zu-e15o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int minimumDistance(vector<int>& nums) {
		unordered_map<int, int> map;
		int n = nums.size();
		vector<int>next(n, -1);
		for (int i = n - 1;i >= 0;i--) {
			if (map.count(nums[i]))next[i] = map[nums[i]];
			map[nums[i]] = i;
		}
		int res = INT_MAX;
		for (int i = 0;i < n;i++) {
			int secondpos = next[i];
			if (secondpos != -1) {
				int thirdpos = next[secondpos];
				if (thirdpos != -1) {
					int dis = 2 * (thirdpos - i);
					res = res > dis ? dis : res;
				}

			}
		}
		return res == INT_MAX ? -1 : res;
	}
};