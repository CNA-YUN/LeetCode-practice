/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int carry = 1;
	*returnSize = digitsSize;
	for (int i = digitsSize - 1;i >= 0;i--) {
		digits[i] += carry;
		if (digits[i] >= 10) {
			if (i == 0)*returnSize += 1;
			carry = 1;
			digits[i] -= 10;
		}
		else carry = 0;
	}
	int* ans = (int*)malloc(*returnSize * sizeof(int));
	if (*returnSize == digitsSize + 1) {
		ans[0] = 1;
	}
	for (int i = 0;i < digitsSize;i++, carry++) {
		ans[carry] = digits[i];
	}
	return ans;
}
void problem66() {
	int digits[] = {9,8,6,4};
	int digitsSize = sizeof(digits) / sizeof(int);
	int size = 2;
	int* returnSize=&size;
	int* ans = plusOne(digits, digitsSize, returnSize);
	int len = *returnSize;
	for (int i = 0;i < len;i++) {
		printf("%d ", ans[i]);
	}
}