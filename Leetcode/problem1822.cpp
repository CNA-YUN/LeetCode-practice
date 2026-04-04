#include <stdio.h>
int arraySign(int* nums, int numsSize) {
	int neg = 0;
	for (int i = 0;i < numsSize;i++) {
		if (nums[i] == 0)return 0;
		else if (nums[i] < 0)neg++;
	}
	if (neg % 2 == 0)return 1;
	else return -1;
}
void problem1822() {
	int nums[] = { -1,1,-1,1,-1 };
	int numsSize = sizeof(nums) / sizeof(int);
	printf("%d", arraySign(nums, numsSize));
}