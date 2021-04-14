/**
 * 
 * @param n int整型 
 * @return int整型
 */
int Fibonacci(int n)
{
    // write code here
    if (n < 0)
        return 0;
    else
    {
        int frist_num = 0, second_num = 1;
        if (!n)
            return frist_num;
        else if (n == 1)
            return second_num;
        int return_num = 0;
        for (int temp_n = 2; temp_n <= n; temp_n++)
        {
            return_num = second_num + frist_num;
            frist_num = second_num;
            second_num = return_num;
        }
        return return_num;
    }
}
