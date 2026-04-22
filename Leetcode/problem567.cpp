/*567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回
true ；否则，返回 false 。

排列 是字符串中所有字符的重新排序。

换句话说，s1 的排列之一是 s2 的 子串 。
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
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2)
            return false;
        bool flag = true;
        vector<int> map(26, 0);

        for (auto& i : s1) {
            map[i - 'a']++;
        }

        for (int j = 0; j < len2; j++) {
            char in = s2[j];
            map[in - 'a']--;
            int left = j - len1 + 1;
            if (left < 0)
                continue;
            flag = true;
            for (auto& k : map) {
                if (k != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;

            char out = s2[left];
            map[out - 'a']++;
        }
        return false;
    }
};
