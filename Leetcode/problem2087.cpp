#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int count(vector<int> array, int low, int high) {
        if (low == high)return 0;
        int res = 0;
        while (low < high) {
            res += array[++low];
        }
        while (low > high) {
            res += array[--low];
        }
        return res;
    }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int res = 0;   // 总代价
        // 移动至家所在行，判断行间移动方向并计算对应代价
        res += count(rowCosts, r1, r2);

        // 移动至家所在位置，判断列间移动方向并计算对应代价
        res += count(colCosts, c1, c2);

        return res;
    }
};

