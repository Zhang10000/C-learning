class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL){
			RandomListNode* node = new RandomListNode(pHead->label);
			return node;
		}
		RandomListNode* pCur = pHead;
		while (pCur != NULL) {
			RandomListNode* node = new RandomListNode(pHead->label);
			node->next = pCur->next;
			pCur->next = node;
			node->next = pCur;
		}
		pCur = pHead;
		while (pCur != NULL) {
			pCur->next->random = pCur->random->next;
			pCur = pCur->next->next;
		}
		pCur = pHead->next;
		RandomListNode* cur = pHead;
		while (pCur->next != NULL) {
			cur->next = cur->next->next;
			cur = cur->next;
			pCur->next = pCur->next->next;
			pCur=pCur->next;
		}
		return pHead->next;
	}
};
