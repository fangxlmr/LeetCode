int removeElement(int* nums, int numsSize, int val) {
    int *slow, *fast, size;

    fast = slow = nums;
    size = numsSize;
    while (fast < nums + numsSize) {
        if (*fast != val) {
            *(slow++) =*fast;
        } else {
            --size;
        }
        ++fast;
    }
    return size;
}