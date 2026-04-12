/*	1343. 大小为 K 且平均值大于等于阈值的子数组数目
 *	给你一个整数数组 arr 和两个整数 k 和 threshold 。
 *	请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left, out;
        int compare = k * threshold;
        int sum = 0;
        int cnt = 0;
        for (int right = 0; right < n; right++) {
            left = right - k + 1;
            sum += arr[right];
            if (left < 0)
                continue;
            else {
                if (left > 0) {
                    sum -= arr[left - 1];
                }
                if (sum >= compare)
                    cnt++;
            }
        }
        return cnt;
    }
};