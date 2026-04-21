/*567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回 true ；否则，返回 false 。

排列 是字符串中所有字符的重新排序。

换句话说，s1 的排列之一是 s2 的 子串 。
*/
#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>hash1;
        unordered_map<char, int>hash2;
        for (auto& i : s1) {
            hash1[i]++;
        }
        int k = s1.size();
        int n = s2.size();
        for (int j = 0;j < n;j++) {
            // 
            hash2[s2[j]]++;
            int left = j - k + 1;
            if (left < 0)continue;
            if (hash1 == hash2)return true;
            char out = s2[left];
            if (hash2[out] == 1) {
                hash2.erase(out);
            }
            else {
                hash2[out]--;
            }

        }
        return false;
    }
};
