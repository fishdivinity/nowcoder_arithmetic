## 题目描述

将给出的链表中的节点每 *k* 个一组翻转，返回翻转后的链表
如果链表中的节点数不是 *k* 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。
要求空间复杂度 *O*(1)

例如：

给定的链表是 1→2→3→4→5

对于 *k*=2, 你应该返回 2→1→4→3→5

对于 *k*=3, 你应该返回 3→2→1→4→5

示例1

## 输入

> {1,2,3,4,5},2

## 返回值

> {2,1,4,3,5}



推荐最后还是使用C语言解决

```cpp
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
    }
};
```

<a href="./analysis.md" style="text-decoration:none">题解</a>

<a href="./code.cpp" style="text-decoration:none">代码</a>

<a href="./printscreen.png" style="text-decoration:none">截图</a>

<a href="../../README.md" style="text-decoration:none">返回目录</a>