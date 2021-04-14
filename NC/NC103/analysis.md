## 解法一:

开辟一个和str长度大小相同的一个字符串ans，把传入的str倒序赋值到ans字符串上， 时间复杂度O(n)*O*(*n*),额外空间复杂度O(n)*O*(*n*)



### c++版本代码：

```cpp
class Solution {
public:
    string solve(string str) {
        string ans = str;
        int len = str.length();
        for(int i = 0 ; i < len ;i++)
        {
                ans[i] = str[len-1-i];
        }
        return ans;
    }
};
```

### java版本代码：

```java
import java.util.*;
public class Solution {
    public String solve (String str) {
        char[] ans = str.toCharArray();
        int len = str.length();
        for(int i = 0 ; i < len ;i++)
        {
                ans[i] = str.charAt(len-1-i);
        }
        return new String(ans);
    }
}
```

### python版本代码：

```python
class Solution:
    def solve(self , str ):
        ans=""
        Len = len(str)
        for i in range(0,Len):
            ans+=str[Len-1-i]
        return ans
```



## 解法二:

原地交换，*str[i] = str[len-1-i]*,注意：交换进行的次数是*len/2*次

时间复杂度O(n)*O*(*n*),额外空间复杂度O(1)*O*(1)

### c++版本代码：



```cpp
class Solution {
public:
    string solve(string str) {
        int len = str.length();
        for(int i = 0 ; i < len/2 ;i++)
        {
                swap(str[i],str[len-1-i]);
        }
        return str;
    }
};
```

### java版本代码：

```java
import java.util.*;
public class Solution {
    public String solve (String str) {
        char[] cstr = str.toCharArray();
        int len = str.length();
        for(int i = 0 ; i < len/2 ;i++)
        {
                char t = cstr[i];
                cstr[i] = cstr[len-1-i];
                cstr[len-1-i]=t;
        }
        return new String(cstr);
    }
}
```



## 解法三:

直接调用库函数

### c++版本代码：

```cpp
class Solution {
public:
    string solve(string str) {
       reverse(str.begin(),str.end());
       return str;
    }
};
```

### java版本代码：

```java
import java.util.*;
public class Solution {
    public String solve (String str) {
        StringBuffer sb =new StringBuffer(str);//此方法针对的是io流，不能针对字符串。
        return sb.reverse().toString();
    }
}
```

### python版本代码：

```python
class Solution:
    def solve(self , str ):
        return str[::-1]
```



转载自：https://blog.nowcoder.net/n/549d6f09118246db9e86c3c45065e7d9

<a href="./topic.md" style="text-decoration:none">../</a>

