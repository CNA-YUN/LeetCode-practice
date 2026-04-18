/*3783. 整数的镜像距离
给你一个整数 n。

定义它的 镜像距离 为：abs(n - reverse(n)) ，其中 reverse(n) 表示将 n 的数字反转后形成的整数。

返回表示 n 的镜像距离的整数。

其中，abs(x) 表示 x 的绝对值。
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
	int mirrorDistance(int n) {
		int res = 0;
		int x = n;
		while (x > 0) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return abs(res-n);
	}
};