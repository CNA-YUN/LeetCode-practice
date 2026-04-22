/*2452. 距离字典两次编辑以内的单词
给你两个字符串数组 queries 和 dictionary 。数组中所有单词都只包含小写英文字母，且长度都相同。

一次 编辑 中，你可以从 queries 中选择一个单词，将任意一个字母修改成任何其他字母。从 queries 中找到所有满足以下条件的字符串：不超过 两次编辑内，字符串与 dictionary 中某个字符串相同。

请你返回 queries 中的单词列表，这些单词距离 dictionary 中的单词 编辑次数 不超过 两次 。单词返回的顺序需要与 queries 中原本顺序相同。
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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int cnt = 0;
        int n = queries[0].size();
        vector<string>res;
        for (auto& q : queries) {
            for (auto& d : dictionary) {
                cnt = 0;
                for (int i = 0;i < n;i++) {
                    if (d[i] != q[i])cnt++;
                }
                if (cnt <= 2) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};