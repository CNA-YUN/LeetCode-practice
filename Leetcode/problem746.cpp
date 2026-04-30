/*746. 使用最小花费爬楼梯
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
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
	int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size(); // 最高台阶数为第 len 阶

		vector<int> dp(len + 1, 0); // dp[i] 为 爬到第 i 阶总共需要支付的最低花费
		dp[0] = 0;         // 第0阶无费用
		dp[1] = 0;         // 第1阶无费用

		for (int i = 2; i <= len; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[len];
	}
};