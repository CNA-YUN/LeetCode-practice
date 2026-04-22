/*438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

字母异位词 是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。
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
	vector<int> findAnagrams(string s, string p) {
		int len1 = s.size();
		int len2 = p.size();
		vector<int> res;
		vector<int> map(26, 0);
		int less = 0;

		if (len1 < len2)
			return res;

		for (auto& i : p) {
			if (map[i - 'a'] == 0) {
				less++;
			}
			map[i - 'a']++;
		}

		for (int j = 0; j < len1; j++) {
			char in = s[j];

			map[in - 'a']--;
			if (map[in - 'a'] == 0) {
				less--;
			}

			int left = j - len2 + 1;

			if (left < 0)
				continue;
			if (less == 0)
				res.push_back(left);

			char out = s[left];

			if (map[out - 'a'] == 0) {
				less++;
			}
			map[out - 'a']++;
		}
		return res;
	}
};