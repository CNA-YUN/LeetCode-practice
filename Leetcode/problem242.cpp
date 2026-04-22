#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if (s_len != t_len)
            return false;
        vector<int> map(26, 0);
        for (auto& i : s) {
            map[i - 'a']++;
        }
        for (auto& j : t) {
            map[j - 'a']--;
        }
        for (auto& k : map) {
            if (k != 0)
                return false;
        }
        return true;
    }
};