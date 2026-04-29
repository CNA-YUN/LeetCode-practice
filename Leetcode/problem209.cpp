/*209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int len = nums.size();
        int cnt = len + 1, sum = 0;
        for (; right < len; right++) {
            sum += nums[right];
            while (sum >= target) {
                cnt = cnt > right - left + 1 ? right - left + 1 : cnt;
                sum -= nums[left];
                left++;
            }
        }
        return cnt <= len ? cnt : 0;
    }
};