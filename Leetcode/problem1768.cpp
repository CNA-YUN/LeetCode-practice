#include <string.h>
#include <malloc.h>
#include <stdio.h>
//˫ָ�뷨
char* mergeAlternately(char* word1, char* word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	int len3 = len1+len2;
	int n1 = 0, n2 = 0, n3 = 0;
	if (len3 == 0)return NULL;
	char* word3 = (char*)malloc((len3+1) * sizeof(char));
	word3[len3]='\0';
	//if (len3 == 0)return NULL;
	while ((n1<len1)||(n2<len2)) {
		if (n1 < len1) {
			word3[n3] = word1[n1++];
			n3++;
		}
		if (n2 < len2) {
			word3[n3] = word2[n2++];
			n3++;
		}
	}
	return word3;
}
void problem1768() {
	char word1[] = {"abcde"};
	char word2[] = "pqr";
	char *word3 = mergeAlternately(word1, word2);
	printf("%s", word3);

}