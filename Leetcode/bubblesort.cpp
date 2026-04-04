#include"stdio.h"
void BubbleSort(int a[], int n) {
	int flag = 1;
	for (int i = 0;i < n - 1;i++) {
		for (int j = n-1;j >i;j--) {
			if (a[j - 1] > a[j]) {
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				flag = 0;
			}
		}
		if (flag)break;
	}
}