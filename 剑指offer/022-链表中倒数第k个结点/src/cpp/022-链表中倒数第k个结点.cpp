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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr||k==0)
            return nullptr;
        ListNode* fast=pListHead;
        ListNode* low=pListHead;
        for(int i=0;i<k-1;i++){
            if(fast->next!=nullptr)
                fast=fast->next;
            else
                return nullptr;
            
        }
        
        while(fast->next!=nullptr){
            fast=fast->next;
            low=low->next;
        }
        
        return low;
    }
};