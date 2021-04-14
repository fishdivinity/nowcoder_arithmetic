### 1，快慢指针解决

判断链表是否有环应该是老生常谈的一个话题了，最简单的一种方式就是快慢指针，**慢指针针每次走一步，快指针每次走两步**，如果相遇就说明有环，如果有一个为空说明没有环。代码比较简单

```java
public boolean hasCycle(ListNode head) {
    if (head == null)
        return false;
    //快慢两个指针
    ListNode slow = head;
    ListNode fast = head;
    while (fast != null && fast.next != null) {
        //慢指针每次走一步
        slow = slow.next;
        //快指针每次走两步
        fast = fast.next.next;
        //如果相遇，说明有环，直接返回true
        if (slow == fast)
            return true;
    }
    //否则就是没环
    return false;
}
```

到这里问题好像并没有结束，为什么快慢指针就一定能判断是否有环。我们可以这样来思考一下，**假如有环，那么快慢指针最终都会走到环上**，假如环的长度是m，快慢指针最近的间距是n，如下图中所示

![](https://uploadfiles.nowcoder.com/images/20201221/606614833_1608541513209/9DCF3E313E4FC0E56D3207D833E60E00)

快指针每次走两步，慢指针每次走一步，所以每走一次快慢指针的间距就要缩小一步，在图一中当走n次的时候就会相遇，在图二中当走m-n次的时候就会相遇。



### 2,存放到集合中

这题还可以把节点存放到集合set中，每次存放的时候判断当前节点是否存在，如果存在，说明有环，直接返回true，比较容易理解

```java
import java.util.Set;
import java.util.HashSet;

public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        while (head != null) {
            //如果重复出现说明有环
            if (set.contains(head))
                return true;
            //否则就把当前节点加入到集合中
            set.add(head);
            head = head.next;
        }
        return false;
    }
}
```

### 3，逐个删除

一个链表从头节点开始一个个删除，**所谓删除就是让他的next指针指向他自己**。如果没有环，从头结点一个个删除，最后肯定会删完，如下图所示
![](https://uploadfiles.nowcoder.com/images/20201221/606614833_1608541714754/0B28908DD8154616AC6BA8577335B42F)
如果是环形的，那么有两种情况，一种是o型的，一种是6型的。原理都是一样，我们就看一下o型的
![](https://uploadfiles.nowcoder.com/images/20201221/606614833_1608541729259/F616B722C8FF288FE7C88E6AF6A22025)

如上图所示，如果删到最后，肯定会出现**head=head.next**；

```java
public boolean hasCycle(ListNode head) {
    //如果head为空，或者他的next指向为空，直接返回false
    if (head == null || head.next == null)
        return false;
    //如果出现head.next = head表示有环
    if (head.next == head)
        return true;
    ListNode nextNode = head.next;
    //当前节点的next指向他自己，相当于把它删除了
    head.next = head;
    //然后递归，查看下一个节点
    return hasCycle(nextNode);
}
```



转载自：https://blog.nowcoder.net/n/846c5a6c596648cba66197c55fe109fd

<a href="./topic.md" style="text-decoration:none">../</a>

