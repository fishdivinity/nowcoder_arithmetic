回文串定义：“回文串”是一个正读和反读都一样的字符串
所以，长度为1的字符串是回文串，例： “a”

进行𝑙𝑒𝑛/2次判断， 如果出现一次 𝑠𝑡𝑟[𝑖] != 𝑠𝑡𝑟[𝑙𝑒𝑛−1−𝑖] 那就不是回文，𝑙𝑒𝑛/2次判断全都相等，那么就是回文串

c++

```cpp
class Solution {
public:
    bool judge(string str) {
        int len = str.length();
        for(int i = 0 ; i < len/2 ;i++)
        {
                if(str[i]!=str[len-1-i])
                        return false;
        }
        return true;
    }
};
```

java

```java
import java.util.*;
public class Solution {
    public boolean judge (String str) {
        int len = str.length();
        for(int i = 0 ; i < len/2 ;i++)
        {
                if(str.charAt(i)!=str.charAt(len-1-i))
                        return false;
        }
        return true;
    }
}
```

python

```python
class Solution:
    def judge(self , str ):
        Len = len(str)//2;
        for i in range(Len):
            if str[i]!=str[len-1-i]:
                return False;
        return True;
```



转载自：https://blog.nowcoder.net/n/e4253fd1ba8942e8978482eba016d3e5

<a href="./topic.md" style="text-decoration:none">../</a>

