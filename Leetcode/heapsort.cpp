#include "stdio.h"
void HeapAdjust(int a[], int k, int len) {
	//调整以k为根节点的子树
	int temp = a[k];
	for (int i = 2 * k + 1;i <= len - 1;i = 2 * i + 1) {
		if (a[i] < a[i + 1] && i < len - 1)i++;
		if (temp >= a[i])break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = temp;
}
void BuildMaxHeap(int a[], int len) {
	for (int i = len / 2 - 1;i >=0;i--) {
		HeapAdjust(a, i, len);
	}
}

void HeapSort(int a[], int len) {
	BuildMaxHeap(a, len);
	for (int i = len - 1;i > 0;i--) {
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		HeapAdjust(a, 0, i);
	}
}