# 描述

此题是非常经典的入门题了。我记得第一次遇到此题是在课堂上，老师拿来讲“递归”的（哈哈哈）。同样的类型的题还有兔子繁殖的问题。大同小异。此题将用三个方法来解决，从入门到会做。
考察知识：递归，记忆化搜索，动态规划和动态规划的空间优化。
难度：一星

# 题解

### 方法一：递归

题目分析，斐波那契数列公式为：f[n] = f[n-1] + f[n-2], 初始值f[0]=0, f[1]=1，目标求f[n]
看到公式很亲切，代码秒秒钟写完。

```C
int Fibonacci(int n) {
    if (n==0 || n==1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
```

优点，代码简单好写，缺点：慢，会超时
**时间复杂度**：O(2^n)
**空间复杂度**：递归栈的空间



### 方法二：记忆化搜索

拿求f[5] 举例
![ ](https://uploadfiles.nowcoder.com/images/20200331/284295_1585636370308_1946BA36B55EFC1A019C4017DE68D41D)

通过图会发现，方法一中，存在很多重复计算，因为为了改进，就把计算过的保存下来。
那么用什么保存呢？一般会想到map， 但是此处不用牛刀，此处用数组就好了。

```c
int Fib(int n, vector<int>& dp) {
    if (n==0 || n==1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = Fib(n-1) + Fib(n-2);
}
int Fibonacci(int n) {
    vector<int> dp(45, -1); // 因为答案都是>=0 的， 所以初始为-1，表示没计算过
    return Fib(n, dp);
}
```

**时间复杂度**：O（n）， 没有重复的计算
**空间复杂度**：O（n）和递归栈的空间

### 方法三：动态规划

虽然方法二可以解决此题了，但是如果想让空间继续优化，那就用动态规划，优化掉递归栈空间。
方法二是从上往下递归的然后再从下往上回溯的，最后回溯的时候来合并子树从而求得答案。
那么动态规划不同的是，不用递归的过程，直接从子树求得答案。过程是从下往上。

```cpp
int Fibonacci(int n) {
    vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}
```

**时间复杂度**：O(n)
**空间复杂度**：O(n)
### 继续优化
发现计算f[5]的时候只用到了f[4]和f[3], 没有用到f[2]...f[0],所以保存f[2]..f[0]是浪费了空间。
只需要用3个变量即可。

```c
int Fibonacci(int n) {
     if (n == 0 || n == 1) return n;
        int a = 0, b = 1, c;
        for (int i=2; i<=n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
}
```

**时间复杂度**：O（n）
**空间复杂度**：O（1）
完美！



转载自：https://blog.nowcoder.net/n/74fccc24fd324385a981bbd1bb53c01f

<a href="./topic.md" style="text-decoration:none">../</a>

