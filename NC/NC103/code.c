/**
 * 反转字符串
 * @param str string字符串 
 * @return string字符串
 */
char* solve(char* str ) {
    // write code here
    int len = strlen(str);
    int len_2 = len / 2;
    len -= 1;
    for(int i = 0; i < len_2; i++)
    {
        str[i] += str[len - i];
        str[len - i] = str[i] - str[len - i];
        str[i] = str[i] - str[len - i];
    }
    return str;
}
