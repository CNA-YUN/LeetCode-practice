/*
2269. 找到一个数字的 K 美丽值
一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：

 * 子字符串长度为 k 。
 * 子字符串能整除 num 。

给你整数 num 和 k ，请你返回 num 的 k 美丽值。

注意：

 * 允许有 前缀 0 。
 * 0 不能整除任何值。

一个 子字符串 是一个字符串里的连续一段字符序列。
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
    int divisorSubstrings(int num, int k) {
        int len = 0;
        int n = num;
        vector<int> arr;
        int outsize = pow(10, k - 1);
        while (n != 0) {
            len++;
            arr.insert(arr.begin(), n % 10);
            n = n / 10;
        }

        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum * 10 + arr[i];
            int left = i - k + 1;
            if (left < 0) {
                continue;
            }
            if (sum != 0 && num % sum == 0) {
                cnt++;
            }
            int out = arr[left];
            sum -= out * outsize;
        }
        return cnt;
    }
};
