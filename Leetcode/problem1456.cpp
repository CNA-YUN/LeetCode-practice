//定长子串中元音的最大数目
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int res = 0;
        int left, out;
        bool flag = false;
        for (int right = 0; right < n; right++) {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u') {
                cnt++;
            }
            out = right - k;
            if (out >= 0) {
                if (s[out] == 'a' || s[out] == 'e' || s[out] == 'i' ||
                    s[out] == 'o' || s[out] == 'u') {
                    cnt--;
                }
            }

            res = cnt > res ? cnt : res;
        }
        return res;
    }
};