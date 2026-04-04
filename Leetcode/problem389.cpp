#include<string.h>
#include<stdlib.h>
#include <stdio.h>
// 利用hash表，先用t映射到hash表，再遍历s减去hash表中的值，hash表中剩余值为1的元素就是多余的字符
char findTheDifference(char* s, char* t) {
	int hash_map[26] = { 0 };
	for (int i = 0;i < strlen(t);i++) {
		hash_map[t[i] - 97]++;
	}
	for (int i = 0;i < strlen(s);i++) {
		hash_map[s[i] - 97]--;
	}
	for (int i = 0;i < 26;i++) {
		if (hash_map[i] != 0) {
			return (char)(i + 97);
		}
	}
	return NULL;
}
void problem389() {
	char s[] = "abcde";
	char t[] = "acdbwe";
	printf("%c", findTheDifference(s,t));
}