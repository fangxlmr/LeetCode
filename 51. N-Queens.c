/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 **/

typedef struct Queens {
    char ***queens[1000];   /* result array */
    int count;  /* point to the free position in queen[1000] */
}Queens, *pQueens;


void nqueen (int row, int n, int *res, pQueens Q);
void save (int n, int *res, pQueens Q);
bool check (int row, int *res);


char*** solveNQueens(int n, int* returnSize) {
    if (n < 1 || returnSize == NULL)
        return NULL;
    pQueens Q = (pQueens) calloc(1, sizeof(Queens));
    int res[n];
    memset(res, 0, sizeof(res));
    nqueen (0, n, &res, Q);
    *returnSize = Q->count;
    return Q->queens;
}



/* backtracking */
void nqueen (int row, int n, int *res, pQueens Q) {
    if (row == n){      /* meet the end of chessboard, save result */
        save(n, res, Q);
        return;
    }
    /* backtracking from 0 to n - 1 */
    for (int i = 0; i < n; ++i) {
        res[row] = i;
        if (check(row, res))  /* validate the position */
            nqueen(row + 1, n, res, Q);     /* go on with next line of chessboard */
    }
}

/* save the correct result into Q->queens */
void save (int n, int *res, pQueens Q) {
    char **matrix = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {   /* create the string matrix of each solution */
        matrix[i] = (char *) calloc((n + 1), sizeof(char));
        int j;
        for (j = 0; j < n; ++j) {
            matrix[i][j] = '.';
        }
        matrix[i][res[i]] = 'Q';    /* the Queen position in each line */
    }
    *(Q->queens + Q->count) = matrix;
    ++Q->count;     /* point to next free position */
    return;
}


/* validate the position of THE queen */
bool check (int row, int *res) {
    for (int i = 0; i < row; ++i) {     /* judge condition */
        if (res[row] == res[i] || abs(res[row] - res[i]) == (row - i))
            return false;   /* invalid */
    }
    return true;    /* valid */
}