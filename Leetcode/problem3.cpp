#include<string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int hash_array[128] = { 0 };
    int leng = 0;
    int max = 0;
    if (len == 1)return 1;
    for (int i = 0;i < len - 1;i++) {
        leng += 1;
        hash_array[s[i]] += 1;
        for (int j = i + 1;j < len;j++) {
            if (hash_array[s[j]] != 0) {
                if (max < leng)max = leng;
                leng = 0;
                for (int n = 0;n < 128;n++) {
                    hash_array[n] = 0;
                }
                break;
            }
            else {
                hash_array[s[j]] += 1;
                leng += 1;
                if (max < leng)max = leng;
            }
        }

        for (int n = 0;n < 128;n++) {
            hash_array[n] = 0;
        }
        leng = 0;
    }
    return max;
}
void problem3() {
    char s[] = "abcabcbb";
    int ans;
    ans = lengthOfLongestSubstring(s);
    printf("maxlength= %d", ans);
}