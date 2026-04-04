void insertsort(int a[], int len) {
	int temp,j;
	for (int i = 1;i < len;i++) {
		if (a[i] < a[i - 1]) {
			temp = a[i];
			for (j = i - 1;j >= 0 && a[j] > temp;j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
	}
}