#include <string.h>
bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);
	//bool match = true;
	for (int a = 1;a <= len / 2;a++) {
		if (len % a == 0) {
			bool match = true;
			for (int j = a;j < len;j++) {
				if (s[j] != s[j - a]) {
					match = false;
					break;
				}
			}
			if (match == true)return true;
		}
		
	}
	return false;
}