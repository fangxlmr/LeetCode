char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int low, mid, high;
    
    low = 0;
    high = lettersSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (letters[mid] <= target) {
            low = mid + 1;
        } else {
            if (mid == 0 || letters[mid - 1] <= target) {
                return letters[mid];
            } else {
                high = mid - 1;
            }
        }
    }
    return letters[0];
}