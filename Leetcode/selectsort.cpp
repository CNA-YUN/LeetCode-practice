#include"stdio.h"
void SelectSort(int a[], int n) {
	int min ;
	int id ;
	for (int i = 0;i < n-1;i++) {
		min = a[i];
		id = i;
		for (int j = i + 1;j < n;j++) {
			if (a[j] < min) {
				id = j;
				min = a[j];
			}
		}
		int temp = a[i];
		a[i] = min;
		a[id] = temp;

	}
}
//int main() {
//	int a[] = { 6,5,4,3,2,1 };
//	SelectSort(a, 6);
//	for (int i = 0;i < 6;i++) {
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}