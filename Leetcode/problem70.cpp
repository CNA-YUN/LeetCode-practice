/*70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。
你有多少种不同的方法可以爬到楼顶呢？
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
    int climbStairs(int n) {
        vector<int> dp;
        for (int i = 0; i <= n; i++) {
            if (i == 1 || i == 0)
                dp.push_back(1);
            else {
                dp.push_back(dp[i - 1] + dp[i - 2]);
            }
        }
        return dp[n];
    }
};