/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<memory>
using namespace std;
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int low = 0, high = numsSize - 1;
	*returnSize = numsSize;
	int* ans = (int*)malloc(sizeof(int) * numsSize);
	int cnt = numsSize - 1;
	while (low <= high) {
		if (abs(nums[low]) <= abs(nums[high])) {
			ans[cnt] = nums[high] * nums[high];
			cnt--;
			high--;
		}
		else {
			ans[cnt] = nums[low] * nums[low];
			low++;
			cnt--;
		}
	}
	return ans;

}