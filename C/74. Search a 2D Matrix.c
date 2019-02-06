bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int low, mid, high;
    int m, n;

    m = matrixRowSize;
    n = matrixColSize;
    low = 0;
    high = m - 1;
    /* Binary search the right row to be search in.  */
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (matrix[mid][0] == target) {
            return true;
        } else if (matrix[mid][0] > target) {
            high = mid - 1;
        } else {
            if (mid == m - 1 || matrix[mid + 1][0] > target) {
                break;
            } else {
                low = mid + 1;
            }
        }
    }

    /* Binary search target in the specific row of the matrix.  */
    int row = mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (matrix[row][mid] == target) {
            return true;
        } else if (matrix[row][mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
