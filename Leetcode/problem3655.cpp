#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
		int x = 1e9 + 7;
		for (auto& q : queries) {
			int low = q[0];
			int high = q[1];
			int k = q[2];
			int v = q[3];
			for (int j = low; j <= high; j += k) {
				nums[j] = (1LL * nums[j] * v) % x;
			}
		}
		int result = 0;
		for (int num : nums) {
			result ^= num;
		}
		return result;

    }
};