class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
{
    if( pHead == NULL ) return pHead;
 
    ListNode *pre = NULL; //指向前面最晚访问过的不重复结点
    ListNode *p = pHead; //指向当前处理的结点
    ListNode *q = NULL; //指向当前处理结点后面结点
 
    while( p != NULL ) {
        if( p->next != NULL && p->next->val == p->val ) {
            q = p->next;
            while( q != NULL && q->next != NULL && q->next->val == p->val )
                q = q->next;
            if( p == pHead ) 
                pHead = q->next;
            else
                pre->next = q->next;
            p = q->next;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    return pHead;
}
 
};
