bool isMonotonic(int* nums, int numsSize) {
	int sign = 0;
	for (int i = 1;i < numsSize;i++) {
		if (nums[i] - nums[i - 1] > 0) {
			if (sign == 0)sign = 1;
			else if (sign == -1)return false;
		}
		else if (nums[i] - nums[i - 1] < 0) {
			if (sign == 0)sign = -1;
			else if (sign == 1)return false;
		}
	}
	return true;
}