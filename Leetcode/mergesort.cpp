#include"stdio.h"
#include "malloc.h"
void merge(int* arr, int left, int mid, int right) {
	int i, j, k;

	int *temp=(int *)malloc((right-left+1)*sizeof(int));
	
	for (i = left, j = mid + 1, k = 0;i <= mid && j <= right;) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	int id = left;
	for (k = 0;k <= right-left;k++) {
		//temp[k] = arr[left++];
		arr[id++] = temp[k];
	}
	
}
void mergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}