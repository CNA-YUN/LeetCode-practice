#include<string.h>
#include<stdio.h>

bool isAnagram(char* s, char* t) {
	int hash_map[26] = { 0 };
	for (int i = 0;i < strlen(t);i++) {
		hash_map[t[i] - 97]++;
	}
	for (int i = 0;i < strlen(s);i++) {
		hash_map[s[i] - 97]--;
	}
	for (int i = 0;i < 26;i++) {
		if (hash_map[i] != 0) {
			return false;
		}
	}
	return true;
}
void problem242() {
	char s[] = "anagram";
	char t[] = "nagaram";
	printf("%d", isAnagram(s, t));
}