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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr||pHead2==nullptr)
            return nullptr;
        int listLength1=GetListLength(pHead1);
        int listLength2=GetListLength(pHead2);
        ListNode* longListNode=pHead1;
        ListNode* shortListNode=pHead2;
        int difLength=listLength1-listLength2;
        if(listLength1<listLength2){
            shortListNode=pHead1;
            longListNode=pHead2;
            difLength=listLength2-listLength1;
        }
        
        for(int i=0;i<difLength;i++){
            longListNode=longListNode->next;
        }
        
        while(longListNode!=nullptr&&shortListNode!=nullptr&&longListNode->val!=shortListNode->val){
            longListNode=longListNode->next;
            shortListNode=shortListNode->next;
        }
        return longListNode;
    }
    int GetListLength(ListNode* pHead){
        if(pHead==nullptr)
            return 0;
        int length=1;
        while(pHead->next!=nullptr){
            pHead=pHead->next;
            length++;
        }
        return length;
    }
};