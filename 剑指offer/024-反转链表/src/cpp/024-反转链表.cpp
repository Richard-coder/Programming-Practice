/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr)
            return nullptr;
        ListNode* pReservedHead=nullptr;
        ListNode* pNode=pHead;
        ListNode* pPre=nullptr;
        ListNode* pNext=nullptr;
        while(pNode!=nullptr){
            pNext=pNode->next;
            if(pNext==nullptr){
                pReservedHead=pNode;
            }
            pNode->next=pPre;
            pPre=pNode;
            pNode=pNext;
        }
        return pReservedHead;
    }
};