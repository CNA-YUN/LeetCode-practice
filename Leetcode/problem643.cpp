// 子数组最大平均数
/* 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
任何误差小于 10^-5 的答案都将被视为正确答案。
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int out, left;
        int sum = 0, max = INT_MIN;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            out = right - k;
            left = out + 1;
            if (left >= 0) {
                if (out >= 0) {
                    sum -= nums[out];
                }
                max = fmax(sum, max);
            }
        }
        double res = 1.0 * max / k;
        return res;
    }
};