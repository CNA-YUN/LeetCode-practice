/*1652. 拆炸弹
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。
为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

 * 如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
 * 如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
 * 如果 k == 0 ，将第 i 个数字用 0 替换。

由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。
给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
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
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int>res(n, 0);
		vector<int>ncode;
		int sum = 0;
		if (k == 0) {
			return res;
		}
		else if (k > 0) {
			for (auto i : code) {
				ncode.push_back(i);
			}
			for (int i = 0;i < k;i++) {
				ncode.push_back(code[i]);
			}
			for (int i = 1;i < ncode.size();i++) {
				sum += ncode[i];
				int left = i - k + 1;
				if (left < 1)continue;

				// 更新
				res[left - 1] = sum;

				int out = ncode[left];
				sum -= out;
			}
		}
		else {
			for (auto i : code) {
				ncode.push_back(i);
			}
			for (int i = 0;i > k;i--) {
				ncode.insert(ncode.begin(), code[n - 1 + i]);
			}
			k *= -1;
			for (int i = 0;i < ncode.size() - 1;i++) {
				sum += ncode[i];
				int left = i - k + 1;
				if (left < 0)continue;

				// 更新
				res[left] = sum;

				int out = ncode[left];
				sum -= out;
			}
		}
		return res;
	}
};