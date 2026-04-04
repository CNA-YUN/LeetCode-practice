#include <corecrt_malloc.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int nums3Size = nums1Size + nums2Size;
	double* nums3 = (double*)malloc(nums3Size * sizeof(double));
	int i = 0, n1 = 0, n2 = 0;
	while (nums1Size && nums2Size) {
		if (nums1[n1] < nums2[n2]) {
			nums3[i] = nums1[n1];
			i++;
			n1++;
			nums1Size--;
		}
		else {
			nums3[i] = nums2[n2];
			i++;
			n2++;
			nums2Size--;
		}

	}
	while (nums1Size != 0) {
		nums3[i] = nums1[n1];
		i++;
		n1++;
		nums1Size--;
	}
	while (nums2Size != 0) {
		nums3[i] = nums2[n2];
		i++;
		n2++;
		nums2Size--;
	}
	if (nums3Size % 2 == 0) {
		return (nums3[nums3Size / 2] + nums3[nums3Size / 2 - 1]) / 2;
	}
	else return nums3[(nums3Size - 1) / 2];
}
void problem4() {
	int nums1[] = {1, 2};
	int nums2[] = {3,4};
	double mid = findMedianSortedArrays(nums1, 2, nums2, 2);
	printf("%f", mid);
	//return 0;
}