/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left, right, sum;
    int *res;

    *returnSize = 2;
    res = (int *) malloc(*returnSize * sizeof(int));
    if (res) {
        left = 0;
        right = numbersSize - 1;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return res;
}
