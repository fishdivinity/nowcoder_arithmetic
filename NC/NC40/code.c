/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param head1 ListNode类 
 * @param head2 ListNode类 
 * @return ListNode类
 */
#include <stdlib.h>
#define LISTNODE_SIZE sizeof(struct ListNode)

struct ListNode *addInList(struct ListNode *head1, struct ListNode *head2)
{
    // write code here
    if (!head1 || !head2)
        return !head1 ? head2 : head1;

    unsigned char list_size = LISTNODE_SIZE;

    //Reverse list to push stack
    {
        struct ListNode *Hperv = NULL, *Hthis = head1, *Hnext = head1->next;
        while (Hnext != NULL)
        {
            Hthis->next = Hperv;
            Hperv = Hthis;
            Hthis = Hnext;
            Hnext = Hnext->next;
        }
        Hthis->next = Hperv;
        head1 = Hthis;
        Hperv = NULL, Hthis = head2, Hnext = head2->next;
        while (Hnext != NULL)
        {
            Hthis->next = Hperv;
            Hperv = Hthis;
            Hthis = Hnext;
            Hnext = Hnext->next;
        }
        Hthis->next = Hperv;
        head2 = Hthis;
    }

    struct ListNode *head = (struct ListNode *)calloc(list_size, 1);
    struct ListNode *Othis = head1, *Tthis = head2;
    unsigned char scale = 0;
    for (;;)
    {
        if (Othis == NULL)
        {
            while (Tthis)
            {
                struct ListNode *hhead = (struct ListNode *)calloc(list_size, 1);
                scale += Tthis->val;
                hhead->val = scale % 10;
                scale /= 10;
                Tthis = Tthis->next;
                hhead->next = head->next;
                head->next = hhead;
            }
            break;
        }
        if (Tthis == NULL)
        {
            while (Othis)
            {
                struct ListNode *hhead = (struct ListNode *)calloc(list_size, 1);
                scale += Othis->val;
                hhead->val = scale % 10;
                scale /= 10;
                Othis = Othis->next;
                hhead->next = head->next;
                head->next = hhead;
            }
            break;
        }
        struct ListNode *hhead = (struct ListNode *)calloc(list_size, 1);
        scale += (Othis->val + Tthis->val);
        hhead->val = scale % 10;
        scale /= 10;
        hhead->next = head->next;
        head->next = hhead;
        Othis = Othis->next;
        Tthis = Tthis->next;
    }
    Othis = head->next;
    free(head);
    return Othis;
}
