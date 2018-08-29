/*
 * using the idea of quick sort.
 * part the nums array into 2 parts, and quick sort them
 * in descending order, return the pivot position,
 * if pos == k - 1, that's must be k-th largest number,
 * if pos <  k - 1, find k-th number in the right part,
 * otherwise, int left part.
 */
int findKthLargest(int* nums, int numsSize, int k) {
    int left, right, pos;

    left = 0;
    right = numsSize - 1;
    while (1) {
        pos = partition(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        } else if (pos > k - 1) {
            right = pos - 1;
        } else {
            left = pos + 1;
        }
    }
}

void swap(int *v, int x, int y);
int partition(int *v, int left, int right)
{
    int i, last;

    if (left >= right) {
        return right;
    }
    swap(v, left, left + (right - left)/2);
    last = left;
    for (i = left + 1; i <= right; ++i) {
        if (v[i] >= v[left]) {
            swap(v, i, ++last);
        }
    }
    swap(v, left, last);
    return last;
}

void swap(int *v, int x, int y)
{
    int tmp;
    tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;
}