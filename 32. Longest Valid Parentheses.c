/* using stack */
#define push(p) stack[sp++] = p
#define pop()   stack[--sp]
#define top()   stack[sp - 1]
#define is_empty()  sp == 0
#define max(x, y) ((x) > (y) ? (x) : (y))

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (!s || !*s) {
        return 0;
    }

    char *stack[len];
    int sp, ans;
    char *beg, *p, *q;

    sp = ans = 0;
    for (beg = p = s; *p; ++p) {
        if (*p == '(') {
            push(p);
        } else if (is_empty()) {    /* p = ')' and stack is empty */
            beg = p + 1;
            continue;
        } else {        /* p = ')' and stack is not empty */
            pop();
            if (is_empty()) {
                ans = max(ans, p - beg + 1);
            } else {
                ans = max(ans, p - top());
            }
        }
    }
    return ans;
}

#undef max
#undef is_empty
#undef top
#undef pop
#undef push

/* using DP */
#define max(x, y) ((x) > (y) ? (x) : (y))
int longestValidParentheses(char* s) {
    int len;
    len = strlen(s);

    if (len <= 0) {
        return 0;
    }

    int ans;
    int i, front;
    int memo[len];

    ans = 0;
    memset(memo, 0, len * sizeof(int));
    for (i = 1; i < len; ++i) {
        if (*(s + i) == ')') {
            front =  i - memo[i - 1] - 1;

            if (*(s + i - 1) == '(') {
                memo[i] = (i >= 2 ? memo[i - 2] : 0) + 2;
            } else if (front >= 0 && *(s + front) == '(') {
                    memo[i] = memo[i - 1] + (front - 1 >= 0 ? memo[front - 1] : 0) + 2;
            }
            ans = max(ans, memo[i]);
        }
    }

    return ans;
}
#undef max

/* using two pointers */
#define max(x, y) ((x) > (y) ? (x) : (y))
int longestValidParentheses(char* s) {
    char *p, *q;
    int ans;
    int left, right;

    /* left -> right */
    ans = 0;
    left = right = 0;
    for (p = s; *p; ++p) {
        if (*p == '(') {
            ++left;
        } else {
            ++right;
        }

        if (left == right) {
            ans = max(ans, left + right);
        } else if (right > left) {
            left = right = 0;
        }
    }

    /* right -> left */
    left = right = 0;
    for (q = p - 1; *q; --q) {
        if (*q == ')') {
            ++right;
        } else {
            ++left;
        }

        if (left == right) {
            ans = max(ans, left + right);
        } else if (left > right) {
            left = right = 0;
        }
    }

    return ans;
}

#undef max
