/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
struct ListNode* ReverseList(struct ListNode* pHead ) {
    // write code here
    struct ListNode *pThis = pHead,*pNext = pHead,*pPrev = NULL;
    for(;pThis != NULL;)
    {
        pNext = pNext->next;
        pThis->next = pPrev;
        pPrev = pThis;
        pThis = pNext;
    }
    return pPrev;
}
