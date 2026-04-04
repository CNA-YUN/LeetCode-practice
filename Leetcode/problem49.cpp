/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
//#include<string.h>
//#include <stdlib.h>
//typedef struct node {
//    int cnt;
//    int idx[100];
//    char str[102];
//} NODE, * PNODE;
//
//int find(PNODE h, char* strs) {
//    int i = 0;
//
//    while (h[i].cnt) {
//        if (strcmp(h[i].str, strs) == 0)
//            return i;
//        else {
//            i++;
//        }
//    }
//    return -1;
//}
//
//int cmp(const void* a, const void* b) { return *(char*)a - *(char*)b; }
//
//char*** groupAnagrams(char** strs, int strsSize, int* returnSize,
//    int** returnColumnSizes) {
//
//    if (strsSize == 0) {
//        *returnSize = 0;
//        return NULL;
//    }
//
//    NODE *h=new NODE[strsSize];
//    char tmp[101];
//
//    memset(h, 0, sizeof(h));
//    *returnSize = 0;
//    for (int i = 0; i < strsSize; i++) {
//        strcpy(tmp, strs[i]);
//        qsort(tmp, strlen(tmp), sizeof(char), cmp);
//
//        int ret = find(h, tmp);
//        if (ret == -1) {
//            strcpy(h[*returnSize].str, tmp);
//            h[*returnSize].idx[(h[*returnSize].cnt)++] = i;
//            (*returnSize)++;
//        }
//        else
//            h[ret].idx[(h[ret].cnt)++] = i;
//    }
//
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
//    char*** ret = (char***)malloc(sizeof(char**) * (*returnSize));
//    for (int i = 0; i < (*returnSize); i++) {
//        ret[i] = (char**)malloc(sizeof(char*) * h[i].cnt);
//        (*returnColumnSizes)[i] = h[i].cnt;
//        for (int j = 0; j < h[i].cnt; j++) {
//            ret[i][j] = strs[h[i].idx[j]];
//        }
//    }
//
//
//    return ret;
//}

