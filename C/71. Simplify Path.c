/* Accepted using stack, but code is not so good. */
static int check(char *beg, char *end)
{
    if (end - beg == 1) {
        return 1;   /* Situation "//" */
    } else if (end - beg == 2 && *(beg + 1) == '.') {
        return 2;   /* Situation "/./" */
    } else if (end - beg == 3 && \
               *(beg + 1) == '.' && \
               *(beg + 2) == '.') {     /* Situation "/../" */
        return 3;
    } else {
        return 4;
    }
}

void push(char *stack[], int *sp, char *c)
{
    if (c != NULL) {
        stack[*sp] = c;
        (*sp)++;
    }
}

void *pop(char *stack, int *sp)
{
    char *c;

    if (*sp == 0) {
        return NULL;
    } else {
        c = stack[*sp];
        (*sp)--;
        return c;
    }
}

char *get(char *stack[], int *sp)
{
    char *c;

    c = stack[*sp];
    (*sp)++;
    return c;
}

char* simplifyPath(char* path) {
    int len;

    len = strlen(path);
    if (len <= 1) {
        return "/";
    } else {
        char *left, *right;
        char *stack[len];
        int sp, flag;

        left = path;
        right = path + 1;
        sp = 0;

        while (right < path + len) {
            while (*right != '\0' && *right != '/') {
                right++;
            }
            *right = '\0';
            flag = check(left, right);
            switch (flag) {
                case 1:     /* // */
                case 2:     /* /./ */
                    break;
                case 3:     /* /../ */
                    pop(stack, &sp);
                    break;
                default:    /* Other situation */
                    push(stack, &sp, left + 1);
                    break;
            }
            left = right;
            right++;
        }

        if (sp == 0) {
            return "/";
        } else {
            char *s;
            int i = 0;

            s = (char *) malloc(len * sizeof(char));
            if (s) {
                s[0] = '\0';
                while (i != sp) {
                    strcat(s, "/");
                    strcat(s, get(stack, &i));
                }
            }
            return s;
        }
    }
}