char* intToRoman(int num) {
    char *roman[13] = {"M", "CM", "D", "CD",
                       "C", "XC", "L", "XL",
                       "X", "IX", "V", "IV",
                       "I"};
    int number[13] =  {1000, 900, 500, 400,
                       100,  90,  50,  40,
                       10,   9,   5,   4,
                       1};
    int n[13] = {0};
    int i;

    /*
     * 求出每个数字字符的个数，存到n数组中
     */
    i = 0;
    while (num > 0) {
        n[i] = num / number[i];
        num = num % number[i];
        ++i;
    }

    /*
     * 依据数组n，构造roman
     */
    char *ans;
    ans = (char *) malloc(100 * sizeof(char));
    memset(ans, 0, 100 * sizeof(char));
    for (i = 0; i < 13; ++i) {
        if (n[i] != 0) {
            for (int j = 0; j < n[i]; ++j) {
                strcat(ans, roman[i]);
            }
        }
    }

    return ans;
}
