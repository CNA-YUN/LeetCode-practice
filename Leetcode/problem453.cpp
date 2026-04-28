/*453. 最小操作次数使数组元素相等
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。
返回让数组所有元素相等的最小操作次数。
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
	int minMoves(vector<int>& nums) {
		int cnt = 0;
		int minnum = nums[0];
		for (auto& num : nums) {
			if (minnum > num)
				minnum = num;
		}
		for (auto& n : nums) {
			cnt += n - minnum;
		}
		return cnt;
	}
};