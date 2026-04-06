#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 将障碍物存入集合，便于 O(1) 查找
        set<pair<int, int>> obs;
        for (auto& ob : obstacles) {
            obs.insert({ ob[0], ob[1] });
        }

        // 方向向量：北、东、南、西
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };
        int dir = 0; // 0:北, 1:东, 2:南, 3:西
        int x = 0, y = 0;
        int result = 0;

        for (int cmd : commands) {
            if (cmd == -1) {         // 右转
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {  // 左转
                dir = (dir + 3) % 4;
            }
            else {
                // 尝试一步一步移动，每步检查是否碰到障碍物
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obs.count({ nx, ny })) {
                        // 遇到障碍物，停止移动
                        break;
                    }
                    x = nx;
                    y = ny;
                    // 更新最大距离平方
                    int dist2 = x * x + y * y;
                    if (dist2 > result) result = dist2;
                }
            }
        }
        return result;
    }
};