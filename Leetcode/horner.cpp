int Horner(int p[], int n, int x) {
	//p[0..n]为从低次到高次的系数
	int res = p[n];
	for (int i = n - 1;i >= 0;i--) {
		res = res * x + p[i];
	}
	return res;
}
//void horner_test() {
//	int p={5,}
//}