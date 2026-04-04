#include <math.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int longestConsecutive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 1;
    int max = 0;
    if (numsSize == 0) return 0;
    for (int i = 1;i < numsSize;i++) {
        if (nums[i] == nums[i - 1] + 1) {
            count++;
            max = fmax(count, max);
        }
        else if (nums[i] == nums[i - 1]) {
            continue;
        }
        else { max = fmax(count, max);count = 1;continue; }
    }
    return fmax(count, max);
}

