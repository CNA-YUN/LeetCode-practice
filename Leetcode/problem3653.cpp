#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int x = 1e9 + 7;
	int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
		int len = queries.size();
		for (int i = 0; i < len; ++i) {
			int low = queries[i][0];
			int high = queries[i][1];
			int k = queries[i][2];
			int v = queries[i][3];
			for (int j = low; j <= high; j += k) {
				nums[j] = (1LL * nums[j] * v) % x;
			}
		}
		int n = nums.size();
		int result = nums[0];
		for (int i = 1; i < n; ++i) {
			result ^= nums[i];
		}
		return result;
	}
};