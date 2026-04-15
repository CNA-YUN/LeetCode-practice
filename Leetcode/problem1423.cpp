/*1423. 可获得的最大点数
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int len = n - k;
        int s = 0;
        for (auto point : cardPoints) {// 求总和
            s += point;
        }
        if (len == 0)
            return s;
        int sum = 0;
        int res = INT_MAX;
        int l, r;
        for (int i = 0; i < n; i++) {// 构建长度为len的窗口，求 窗口内元素的最小和 res
            // 进数组
            sum += cardPoints[i];
            // 数组长度小于k
            if (i < len - 1)
                continue;
            int left = i - len + 1;
            // 更新数据
            if (res > sum) {
                res = sum;
                l = left;
                r = i;
            }
            // 出数组
            int out = cardPoints[left];
            sum -= out;
        }
        return s - res;// 返回值为 s - res 即 k张牌的最大点数和
    }
};