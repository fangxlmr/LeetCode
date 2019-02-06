/* Approach 1: Binary search each line with O(MlgN) time. [Accepted] */
int helper(int *v, int n, int target)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (v[mid] == target) {
            return true;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i;

    for (i = 0; i < matrixRowSize; ++i) {
        if (helper(matrix[i], matrixColSize, target) == true) {
            return true;
        }
    }
    return false;
}

/* Approach 2: Optimized solution 1. [Accepted]
 * Not faster so much, almost the same speed.
 */
int helper(int *v, int n, int target)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (v[mid] == target) {
            return true;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int limd, mid, limu;
    int i;

    limd = 0;
    limu = matrixRowSize - 1;
    /* Find the lowest limit of rows that possible holds the target. */
    while (limd <= limu) {
        mid = limd + ((limu - limd) >> 1);
        if (matrix[mid][0] > target) {
            limu = mid - 1;
        } else {
            if (mid == matrixRowSize - 1 || matrix[mid + 1][0] > target) {
                limd = mid;
                break;
            } else {
                limd = mid + 1;
            }
        }
    }

    for (i = 0; i <= limd; ++i) {
        if (helper(matrix[i], matrixColSize, target) == true) {
            return true;
        }
    }
    return false;
}

/* Approach 3: Divide and conquer. Really genius. */
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j;

    i = matrixRowSize - 1;
    j = 0;
    while (i >= 0 && j < matrixColSize) {
        if (matrix[i][j] < target) {
            j++;
        } else if (matrix[i][j] == target) {
            return true;
        } else {
            i--;
        }
    }
    return false;
}

