/*1016. 子串能表示从 1 到 N 数字的二进制串
给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n]
范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false
子字符串 是字符串中连续的字符序列。
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool queryString(string s, int n) {
        int len = s.length();
        int x;
        int cnt = 0;
        unordered_set<int> num;
        for (int i = 0; i < len; i++) {
            x = s[i] - '0';
            if (x == 0)
                continue;
            for (int j = i + 1; x <= n; j++) {
                num.insert(x);
                if (j == len)
                    break;
                x = (x << 1) | (s[j] - '0');
            }
        }
        if (num.size() == n) {
            return true;
        }

        else {
            return false;
        }
    }
};