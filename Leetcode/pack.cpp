#include <math.h>
#include <stdio.h>
#define MAX_N 10
#define MAX_W 10
int knapsack(int w[], int v[], int n, int W) {
	// n为物品总数量
	// W为背包最大容量
	// w[0..n-1] 和 v[0..n-1] 表示每个物品的重量和价值
	int dp[MAX_N][MAX_W] = { 0 };
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= W;j++) {
			if (j < w[i - 1])dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = fmax(dp[i - 1][j - w[i - 1]] + v[i], dp[i - 1][j]);
			}
		}
	}
	return dp[n][W];
}
void pack_test() {
	// 给定背包问题的实例
	int weight[] = { 3, 2, 1, 4, 5 };   // 物品重量
	int value[] = { 25, 20, 15, 40, 50 }; // 物品价值
	int n = 5;
	int W = 6;

	int maxValue = knapsack(weight, value, n, W);
	printf("最大总价值: %d\n", maxValue);
}