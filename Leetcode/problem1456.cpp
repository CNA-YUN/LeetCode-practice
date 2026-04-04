//#include <stdin.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int judge(char c) {
    switch (c) {
    case 'a':
        return 1;
    case 'e':
        return 1;
    case 'i':
        return 1;
    case 'o':
        return 1;
    case 'u':
        return 1;
    default:
		return 0;
    }
    
}
int maxVowels(char* s, int k) {
    int cur = 0;
	int len = strlen(s);
	int res = 0;
	int maxn = 0;
    while (cur <= len - k) {
		res = 0;
        for (int i = 0; i < k; i++) {
            if (judge(s[cur + i]))
            {
				res++;
            }
        }
		maxn = max(maxn, res);
		cur++;
    }
	return maxn;
	
}
void problem1456() {
	char s[] = "abciiidef";
	int k = 3;
	printf("%d", maxVowels(s, k));
}