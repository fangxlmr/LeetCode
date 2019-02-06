int myAtoi(char* str) {
    int base = 0, sign = 1;  /* base 为返回的数值， sign为符号 */
    int i = 0;
    while (isspace(str[i])) {   /* 去掉开头的空格 */
        ++i;
    }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        ++i;
    }
    while (isdigit(str[i])) {
        if (base > INT_MAX / 10 ||      /* 判断是否溢出 */
            INT_MAX - base * 10 < (str[i] - '0'))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = base * 10 + (str[i] - '0');
        ++i;
    }
    return sign * base;
}