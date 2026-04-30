/*1461. 检查一个字符串是否包含所有长度为 K 的二进制子串
给你一个二进制字符串 s 和一个整数 k 。
如果所有长度为 k 的二进制字符串都是 s 的子串，请返回 true ，否则请返回 false 。
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
    bool hasAllCodes(string s, int k) {
        // 把子串转成整数，保存到哈希集合或者布尔数组中。
        // 小优化：如果循环过程中发现已经找到 2^k 个不同的二进制数，可以提前返回 true。
        int n = (1 << k) - 1;
        int target = 1 << k;
        unordered_set<int> has;
        int cnt = 0;
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            // 把 s[i] 加到 x 的末尾：x 整体左移一位，然后 按位或 s[i]&1
            // &n 目的是去掉超出 k 的比特位
            x = (x << 1 & n) | (s[i] & 1);
            if (i >= k - 1)
                has.insert(x);
            if (has.size() == target)
                return true;
        }
        return has.size() == target;
    }
};