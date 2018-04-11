#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int myAtoi(char *);

int main(){
    char *s = "9223372036854775809";
    printf("s = %s, len = %d\n", s, strlen(s));
    printf("myAtoi(s) = %d\n", myAtoi(s));
    return 0;
}


int myAtoi(char* str) {
    int len = strlen(str);
    if(!len){ /* 空字符串 */
        return 0;
    }

    int i = 0;
    long long int result = 0;
    int sign = 1;   /*符号位，正数为1，负数为-1*/
    while(i < len){
        if(isspace(str[i])){  /* 判断开头空格 */
            ++i;
            continue;
        }
        else{
            break;
        }
    }
    while(i < len){
        if(str[i] == 43 || str[i] == 45){   /* 判断正负号 */
            sign = 44 - str[i];   /* 若是+号，assic码为43，-号为45，result = 44 - str[i]刚好是符号位 */
            ++i;
        }
        if(!isdigit(str[i])){
            break;
        }
        else{    /* 数字字符 */
            result *= 10;
            result += str[i] - 48;
            ++i;
        }
    }

    if(result == 0)
        return result;
    if(sign > 0){
        return result > INT_MAX ? INT_MAX : result; 
    }
    else{
        result = sign * result;
        return result < INT_MIN ? INT_MIN : result;
    }
}