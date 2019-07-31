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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        ListNode* node=pHead;
        ListNode* front=nullptr;
        ListNode* pnext;
        
        while(node!=nullptr){
            bool needDel=false;
            pnext=node->next;
            if(pnext!=nullptr&&node->val==pnext->val)
                needDel=true;
            if(!needDel){
                front=node;
                node=pnext;
            }else{
                int val=node->val;
                ListNode* toDel=node;
                while(toDel!=nullptr&&toDel->val==val){
                    pnext=toDel->next;
                    delete toDel;
                    toDel=nullptr;
                    toDel=pnext;
                }
                if(front==nullptr)
                    pHead=pnext;
                else
                    front->next=pnext;
                node=pnext;
            }
        }
        
        return pHead;
    }
};