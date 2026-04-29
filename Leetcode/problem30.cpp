/*30. 串联所有单词的子串
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
 例如，如果 words = [ab,cd,ef]， 那么 abcdef， abefcd，cdabef， cdefab，efabcd， 和 efcdab 都是串联子串。
 acdbef 不是串联子串，因为他不是任何 words 排列的连接。

返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordlen = words[0].size();
        int windowlen = words.size() * wordlen;
        unordered_map<string, int> targetcnt;
        for (auto& word : words) {
            targetcnt[word]++;
        }
        vector<int> ans;
        for (int start = 0; start < wordlen; start++) {
            unordered_map<string, int> cnt;
            int overload = 0;
            for (int right = start + wordlen; right <= s.size();
                right += wordlen) {
                string in_word =
                    s.substr(right - wordlen,
                        wordlen); // 从right-wordlen开始,取wordlen个字符
                if (cnt[in_word] == targetcnt[in_word]) {
                    overload++;
                }
                cnt[in_word]++;
                int left = right - windowlen;
                if (left < 0) {
                    continue;
                }

                if (overload == 0) {
                    ans.push_back(left);
                }

                string out_word = s.substr(left, wordlen);
                cnt[out_word]--;
                if (cnt[out_word] == targetcnt[out_word]) {
                    overload--;
                }
            }
        }
        return ans;
    }
};