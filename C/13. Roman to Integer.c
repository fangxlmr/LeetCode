/*
 * 最简单的办法，但是时间复杂度较高
 */
int romanToInt(char *s)
{
    int  num;
    char *index;

    num = 0;
    index = s;

    if (s == NULL) {
        return 0;
    }
    while (*index != '\0') {
        switch (*index) {
            case 'I':
                if (*(index + 1) == 'V') {
                    num += 4;
                    ++index;
                } else if (*(index + 1) == 'X') {
                    num += 9;
                    ++index;
                } else {
                    num += 1;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                if (*(index + 1) == 'L') {
                    num += 40;
                    ++index;
                } else if (*(index + 1) == 'C') {
                    num += 90;
                    ++index;
                } else {
                    num += 10;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if (*(index + 1) == 'D') {
                    num += 400;
                    ++index;
                } else if (*(index + 1) == 'M') {
                    num += 900;
                    ++index;
                } else {
                    num += 100;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
        }
        ++index;
    }

    return num;
}

/*
 * 利用hashmap的办法，提高访问效率，避免无意义的判断
 */
int hash(int c)
{
    return c % 23;
}

int romanToInt(char *s)
{
    char t[] = "IVXLCDM";
    int map[100];
    char *index;
    int num;

    num = 0;
    /*
     * 创建字符的hashmap
     */
    index = t;
    while (*index != '\0') {
        switch (*index) {
            case 'I':
                map[hash(*index)] = 1;
                break;
            case 'V':
                map[hash(*index)] = 5;
                break;
            case 'X':
                map[hash(*index)] = 10;
                break;
            case 'L':
                map[hash(*index)] = 50;
                break;
            case 'C':
                map[hash(*index)] = 100;
                break;
            case 'D':
                map[hash(*index)] = 500;
                break;
            case 'M':
                map[hash(*index)] = 1000;
                break;
        }
        ++index;
    }

    /*
     * 解析roman字符串
     */
    index = s;
    while (*index != '\0') {
        if (*(index + 1) == '\0' || map[hash(*index)] >= map[hash(*(index + 1))])
        {
            num += map[hash(*(index))];
        } else {
            num -= map[hash(*index)];
        }
        ++index;
    }
    return num;
}

