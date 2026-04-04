/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
#include <stdio.h>
int* occurrencesOfElement(int* nums, int numsSize, int* queries, int queriesSize, int x) {
	int* answer = (int*)malloc(queriesSize * sizeof(int));
	int i = 0;
	while (queriesSize) {
		for (int j = 0;j < numsSize;j++) {
			if (nums[j] == x) {
				queries[i]--;
				if (queries[i] == 0) {
					answer[i] = j;
					break;
				}
			}
			
		}
		if (queries[i] != 0)answer[i++] = -1;
		else i++;
		queriesSize--;
	}
	return answer;
}
void problem3159() {
	int nums[] = { 1,3,1,7 };
	int queries[] = { 1,3,2,4 };
	int x = 1;
	int* returnSize ;
	int size = 4;
	returnSize = &size;
	int *ans = occurrencesOfElement(nums, 4, queries, 4, 1);
	/*printf("%d",occurrencesOfElement(nums, 4, queries, 4, 1));*/
	for (int i = 0;i < 4;i++) {
		printf("%d\n", ans[i]);
	}
}