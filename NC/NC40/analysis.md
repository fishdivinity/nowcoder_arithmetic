**采用栈的先进后出的思想计算每一位的累加和**

```cpp
/**
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
class Solution
{
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode addInList(ListNode *head1, ListNode *head2)
    {
        // write code here
        stack<int> st1; //存储链表1的数据
        stack<int> st2; //存储链表2的数据

        while (head1 || head2) //head1和head2都遍历完时推出循环
        {
            if (head1)
            {
                st1.push(head1->val);
                head1 = head1->next;
            }
            if (head2)
            {
                st2.push(head2->val);
                head2 = head2->next;
            }
        }
        ListNode *vhead = new ListNode(-1);
        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry != 0) //这里设置carry!=0,是因为当st1,st2都遍历完时，如果carry=0,就不需要进入循环了
        {
            int a = 0, b = 0;
            if (!st1.empty())
            {
                a = st1.top();
                st1.pop();
            }
            if (!st2.empty())
            {
                b = st2.top();
                st2.pop();
            }
            int get_sum = a + b + carry;       //每次的和应该是对应位相加再加上进位
            int ans = get_sum % 10;            //对累加的结果取余
            carry = get_sum / 10;              //如果大于0，就进位
            ListNode *cur = new ListNode(ans); //创建节点
            cur->next = vhead->next;
            vhead->next = cur; //每次把最新得到的节点更新到vhead->next中
        }
        return vhead->next;
    }
};
```



转载自：https://blog.nowcoder.net/n/aebf05ae578f493d89d1c8356be5c3d4

<a href="./topic.md" style="text-decoration:none">../</a>

