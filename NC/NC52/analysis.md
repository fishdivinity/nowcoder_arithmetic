题目中给出的字符串仅包含字符'(',')','{','}','['和']',
对字符串中的每一个字符进行遍历，如果是右括号的话，需要看一下栈顶元素是不是和它匹配的左括号。如果是的话，那这两个括号是一对，让栈顶元素出栈
不满足配对条件的话，就让该元素进栈
如果字符串是一个合法的括号序列，那么整个字符串遍历完毕以后，栈是空的，即所有的右括号都右匹配的左括号。
如果栈内还右元素，就不是合法的括号序列
c++代码

```CPP
class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i = 0 ; i < s.length(); i++)
        {
            if(c.empty())
            {
                c.push(s[i]);
                continue;
            }
            if(s[i]==')'&&c.top()=='('){c.pop();}
            else if(s[i]=='}'&&c.top()=='{'){c.pop();}
            else if(s[i]==']'&&c.top()=='['){c.pop();}
            else{ c.push(s[i]);}
        }
        return c.empty();
    }
};
```

java代码

```java
import java.util.*;
import java.util.Stack;
public class Solution {
    public boolean isValid (String s) {
        Stack<Character> c = new Stack<Character>();
        for(int i = 0 ; i < s.length(); i++){
            if(c.empty()){
                c.push(s.charAt(i));
                continue;
            }
            if(s.charAt(i)==')'&&c.peek()=='('){c.pop();}
            else if(s.charAt(i)=='}'&&c.peek()=='{'){c.pop();}
            else if(s.charAt(i)==']'&&c.peek()=='['){c.pop();}
            else{ c.push(s.charAt(i));}
        }
        return c.empty();
    }
}	
```

python代码

```python
class Solution:
    def isValid(self , s ):
        stack = []
        for i in s:
            if len(stack)==0:
                stack.append(i)
                continue
            if i==')' and stack[-1]=='(':
                stack.pop()
            elif i=='}' and stack[-1]=='{':
                stack.pop()
            elif i==']' and stack[-1]=='[':
                stack.pop()
            else:
                stack.append(i)
        if len(stack)==0:
            return True
        else:
            return False
```



转载自：https://blog.nowcoder.net/n/a489d77c97ea4a31a319260538c7ef1b

<a href="./topic.md" style="text-decoration:none">../</a>

