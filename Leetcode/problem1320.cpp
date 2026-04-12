// leetcode 1320.二指输入的最小距离
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int dist(int a, int b, int x[], int y[]) {
        if (a == -1 || b == -1) return 0;
        return abs(x[a] - x[b]) + abs(y[a] - y[b]);
    }

    int dfs(int i, int other, int n, int x[], int y[], string& word, vector<vector<int>>& memo) {
        // i : 当前要输入的字符下标 (0 ~ n-1)
        // other : 空闲手指所在的字母索引 (0~25) 或 -1
        if (i == n) return 0;
        if (memo[i][other + 1] != -1) return memo[i][other + 1];

        int cur = word[i] - 'A';
        int prev = (i > 0) ? (word[i - 1] - 'A') : -1;

        // 情况1：用空闲手指 (other) 按 cur
        int cost1 = dist(other, cur, x, y) + dfs(i + 1, prev, n, x, y, word, memo);
        // 情况2：用非空闲手指 (prev) 按 cur
        int cost2 = dist(prev, cur, x, y) + dfs(i + 1, other, n, x, y, word, memo);

        return memo[i][other + 1] = min(cost1, cost2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        if (n <= 1) return 0;

        // 键盘坐标：6列，按字母顺序 A~Z 依次排列
        int x[26], y[26];
        for (int i = 0; i < 26; i++) {
            x[i] = i % 6;
            y[i] = i / 6;
        }

        // memo[i][other+1] : other 从 -1 到 25，所以第二维大小 27
        vector<vector<int>> memo(n, vector<int>(27, -1));
        // 初始状态：i=0，空闲手指未使用 (-1)，另一个手指未定义（用 -1 表示）
        // 注意：第一个字符必须由某个手指按，且可以从任意位置开始（距离 0）
        // 我们的递归已经处理了 prev = -1 时 dist(-1,cur)=0 的情况
        return dfs(0, -1, n, x, y, word, memo);
    }
};