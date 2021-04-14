/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 
 * @param str string字符串 待判断的字符串
 * @return bool布尔型
 */
#include<stdbool.h>

bool judge(char* str ) {
    // write code here
    int len = strlen(str);
    int len_2 = len / 2;
    len -= 1;
    for(int i = 0; i < len_2; i++)
    {
        if(str[i] != str[len - i])
            return false;
    }
    return true;
}
//解法一：对半比较
//使用变量存储只需要计算一次的结果，可以降低程序的运行时间
