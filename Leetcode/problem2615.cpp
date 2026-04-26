/*2615. 等值距离和
给你一个下标从 0 开始的整数数组 nums 。
现有一个长度等于 nums.length 的数组 arr 。
对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 |i - j| 之和。
如果不存在这样的 j ，则令 arr[i] 等于 0 。
返回数组 arr 。
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
	vector<long long> distance(vector<int>& nums) {
		unordered_map<int, vector<int>>hash;
		int len = nums.size();

		for (int i = 0, n = nums.size();i < n;i++) {
			hash[nums[i]].push_back(i);
		}

		vector<long long>arr(len, 0);

		for (auto& pair : hash) {
			int sum = 0;
			int j = 0;
			for (int i = j + 1, m = pair.second.size();i < m;i++) {
				sum += abs(pair.second[j] - pair.second[i]);
			}

			for (auto& i : pair.second) {
				arr[i] = sum;
			}
		}
		return arr;

	}
};