# 描述

------

这是一道对栈和队列之间灵活转化的题目。
难度：一星
考察知识：队列，栈

------

# 题解

## 方法：模拟

如果我知道队列是FIFO，栈是FILO，但是这道题我还是不知道怎么写怎么办？
对于这种感觉不难，但是又不会写的，方法就是模拟。
比如有如下操作：(pop操作确保栈中有元素）

> push(1);push(2);pop(3);push(4);

![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400497769_0C4ABEBEC33645F04FC3BE80560A19CA)
根据队列的特性，只能pop(1),pop(2),pop之后的结果
![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400552969_2BD71B6015DA622EC901AE9E8EF11B09)

上述是队列的操作。
当push的时候，我们必须要用一个stack来存，假设用stack1来存。
![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400791591_E15AD689EC5617B74FCBAB036DB5F203)
那么push操作解决了。那么pop操作怎么办呢？
如果pop(1)，但是此时在stack1的栈底，如果要pop，必须再将stack1中的数据push到stack2中，然后在pop，如图
![ ](https://uploadfiles.nowcoder.com/images/20200328/284295_1585401602901_0711311756A500BE23FE8ED82FCA5FF3)

这样直接弹出stack2的栈顶就可以了。
如果要继续pop，那就继续弹出stack2就可以了

------

但是现在总感觉哪里还是有点问题。如果是这样就继续测试几个例子。
如果push(5)，
![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585401399745_2DA9470B0EA9FAE77932FA8176C79036)

#### **所以最后总结一下**：push操作就直接往stack1中push， pop操作需要分类一下：如果stack2为空，那么需要将stack1中的数据转移到stack2中，然后在对stack2进行pop，如果stack2不为空，直接pop就ok。

## 复杂度分析

时间复杂度：push操作为O(1),pop操作为O(1)
空间复杂度：需要stack来存，O(n)

## 代码

```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```



转载自：https://blog.nowcoder.net/n/dacd6b3e1fa34cd68d99a37746ac77a2

<a href="./topic.md" style="text-decoration:none">../</a>

