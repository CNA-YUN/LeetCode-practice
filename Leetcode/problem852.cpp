int peakIndexInMountainArray(int* arr, int arrSize) {
	int left = 0;
	int right = arrSize - 1;
	int mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid - 1]<arr[mid] && arr[mid]>arr[mid + 1])return mid;
		if (arr[mid - 1] > arr[mid]) {
			right = mid ;
		}
		else if (arr[mid] < arr[mid + 1]) {
			left = mid ;
		}
	}
	return mid;
}