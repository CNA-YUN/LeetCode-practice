#include <math.h>
//暴力贪婪算法
int maxArea_violent(int* height, int heightSize) {
	int ans_low = 0, ans_high = heightSize - 1, max_area = (heightSize-1)*fmin(height[0],height[heightSize-1]);
	int area;
	for (int i = 0;i < heightSize-1;i++) {
		for (int j = heightSize - 1;j > i;j--) {
			area = (j - i) * fmin(height[i], height[j]);
			if (area > max_area) {
				max_area = area;
				/*ans_low = i;
				ans_high = j;*/
			}
		}
	}
	return max_area;
}
//复杂度O(n)的双指针移动。
//两个指针一个指向开头一个指向结尾，此时容器的底是最大的，
//接下来随着指针向内移动，会造成容器的底变小，在这种情况下想要让容器盛水变多，就只有在容器的高上下功夫。
//那我们该如何决策哪个指针移动呢？
//我们能够发现不管是左指针向右移动一位，还是右指针向左移动一位，容器的底都是一样的，都比原来减少了 1。
//这种情况下我们想要让指针移动后的容器面积增大，就要使移动后的容器的高尽量大，
//所以我们选择指针所指的高较小的那个指针进行移动，
//这样我们就保留了容器较高的那条边，放弃了较小的那条边，以获得有更高的边的机会。
int maxArea(int* height, int heightSize) {
	int ans_low = 0, ans_high = heightSize - 1, max_area = (heightSize - 1) * fmin(height[0], height[heightSize - 1]);
	int area;
	while (ans_low < ans_high) {
		area = (ans_high - ans_low) * fmin(height[ans_high], height[ans_low]);
		max_area = fmax(max_area, area);
		if (height[ans_high] > height[ans_low])ans_low++;
		else ans_high--;
	}
	return max_area;
}