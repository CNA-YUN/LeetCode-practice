/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXNUM 200001
#define PIANYI 100000
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//	int hash_map[MAXNUM] = { 0 };
//	int twosum;
//	int ans[1000][3];
//	int cnt = 0;
//	for (int i = 0;i < numsSize;i++) {
//		hash_map[nums[i] + PIANYI]++;
//	}
//	for (int i = 0;i < MAXNUM;i++) {
//		if (hash_map[i] != 0)cnt++;
//	}
//	int *hash_nonull=new int[cnt];
//	//int ans[cnt / 3 + 1][3];
//
//	for (int i = 0,j=0;i < MAXNUM;i++) {
//		if (hash_map[i] != 0) {
//			hash_nonull[j] = i - PIANYI;
//			j++;		
//		};
//	}
//
//	for (int i = 0;i < numsSize;i++) {
//		twosum = 0 - nums[i];
//		hash_map[nums[i] + PIANYI] = 0;
//		for (int j = 0;j < MAXNUM;j++) {
//			if (hash_map[j] != 0) {
//				if (hash_map[twosum - j + 2 * PIANYI] != 0) {
//					hash_map[j] = 0;
//					hash_map[twosum - j + 2 * PIANYI] = 0;
//					
//				}
//			}
//		}
//	}
//}