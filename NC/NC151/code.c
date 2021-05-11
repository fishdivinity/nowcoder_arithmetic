/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 求出a、b的最大公约数。
 * @param a int 
 * @param b int 
 * @return int
 */
int gcd(int a, int b)
{
    // write code here
    if (a % b == 0 || b % a == 0)
        return a % b == 0 ? b : a;
    if (a % 2 == 0 && b % 2 == 0)
    {
        while (a % 2 == 0 && b % 2 == 0)
        {
            a = a / 2;
            b = b / 2;
        }
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a * 2;
    }
    else
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
}
