#include <string.h>
#include <stdio.h>
int lengthOfLastWord(char* s) {
	int len = strlen(s);
	if (len == 0)return 0;
	int start = -1, end = -1;
	for (int i = len-1;i >=0;i--) {
		if (start != -1 && end != -1)break;
		if (s[i] != ' ') {
			if (end==-1) {
				end = i;
			}
		}
		else {
			if(end!=-1){
				start = i + 1;
				return end - start + 1;
			}
		}
	}
	if (start == -1) {
		if (end == -1)return 0;
		else return 1;
	}
	return end - start + 1;
}
void problem58() {
	char s[] = "day";
	printf("%d", lengthOfLastWord(s));
}