typedef struct {
    int num;
    int index;
} Number;

int compare(const void* a, const void* b) {
    return ((Number*)a)->num - ((Number*)b)->num;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Number numbers[numsSize];
    for (int i = 0; i < numsSize; i++) {
        numbers[i].num = nums[i];
        numbers[i].index = i;
    }

    qsort(numbers, numsSize, sizeof(Number), compare);

    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = numbers[left].num + numbers[right].num;
        if (sum == target) {
            *returnSize = 2;
            int* result = (int*)malloc(*returnSize * sizeof(int));
            result[0] = numbers[left].index;
            result[1] = numbers[right].index;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0; // No valid pair found
    return NULL;
}
