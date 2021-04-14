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
        if(!head || k<= 1)
            return head;
        //定义三个指针，分别指向前一个，当前这个，下一个
        ListNode *prev = nullptr, *current = head, *next = nullptr;
        //遍历检查一下节点是否小于k
        for(int i = 0; i < k; i++)
        {
            if(!current)
                return head;
            current = current->next;
        }
        //开始分段反向排序
        current = head;
        for(int i = 0; i < k; i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //递归调用函数
        head->next = reverseKGroup(next, k);
        return prev;
    }
};
