/*3679. 使库存平衡的最少丢弃次数
给你两个整数 w 和 m，以及一个整数数组 arrivals，其中 arrivals[i] 表示第 i 天到达的物品类型（天数从 1 开始编号）。
物品的管理遵循以下规则：
 * 每个到达的物品可以被 保留 或 丢弃 ，物品只能在到达当天被丢弃。
 * 对于每一天 i，考虑天数范围为 [max(1, i - w + 1), i]（也就是直到第 i 天为止最近的 w 天）：
 * 对于 任何 这样的时间窗口，在被保留的到达物品中，每种类型最多只能出现 m 次。
 * 如果在第 i 天保留该到达物品会导致其类型在该窗口中出现次数 超过 m 次，那么该物品必须被丢弃。

返回为满足每个 w 天的窗口中每种类型最多出现 m 次，最少 需要丢弃的物品数量。
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
	int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
		unordered_map<int, int> cnt;
		int ans = 0;
		for (int i = 0; i < arrivals.size(); i++) {
			int& x = arrivals[i];
			// x 进入窗口
			if (cnt[x] == m) { // x 的个数已达上限
				// 注意 x 在未来要离开窗口，但由于已经丢弃，不能在离开窗口时修改 cnt
				// 这里直接置为 0，未来离开窗口就是 cnt[0]--，不影响答案
				x = 0; // 丢弃 arrivals[i]
				ans++;
			}
			else {
				cnt[x]++;
			}

			// 左端点元素离开窗口，为下一个循环做准备
			int left = i + 1 - w;
			if (left >= 0) {
				cnt[arrivals[left]]--;
			}
		}
		return ans;
	}
};
