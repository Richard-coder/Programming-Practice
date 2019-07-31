/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        ListNode* meetingNode=FindMeetingNode(pHead);
        if(meetingNode==nullptr)
            return nullptr;
        ListNode* p1=meetingNode->next;
        int num=1;
        while(p1!=meetingNode){
            p1=p1->next;
            num++;
        }
        
        ListNode* p2=pHead;
        
        while(num>0){
            p2=p2->next;
            num--;
        }
        
        p1=pHead;
        
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        
        return p1;
    }
    
    ListNode* FindMeetingNode(ListNode* pHead){
        if(pHead==nullptr||pHead->next==nullptr)
            return nullptr;
        ListNode* slow=pHead;
        ListNode* fast=slow->next;
        
        while(slow!=nullptr&&fast!=nullptr){
            if(slow==fast)
                return slow;
            slow=slow->next;
            fast=fast->next;
            if(fast!=nullptr)
                fast=fast->next;
        }
        return nullptr;
    }
};