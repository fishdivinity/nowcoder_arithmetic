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
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *pThis = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                pThis->next = l1;
                l1 = l1->next;
            }
            else
            {
                pThis->next = l2;
                l2 = l2->next;
            }
            pThis = pThis->next;
        }
        pThis->next = (!l1) ? l2 : l1;
        pThis=head->next;
        delete head;
        return pThis;
    }
};
