/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    //使用栈结构的方法
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*> nodes;//由于链表结构简单，用一个辅助变量即可，可以不用栈
        
        ListNode *pNode=head;
        while(pNode!=NULL){
            nodes.push(pNode);
            pNode=pNode->next;
        }
        //为了效率使用静态vector，使用静态vector后不能使用push_back
        vector<int> res(nodes.size());
        int i=0;
        while(!nodes.empty()){
            pNode=nodes.top();
            res[i++]=pNode->val;
            nodes.pop();
        }
        return res;
    }
    //使用递归的方法
    vector<int> res;
    vector<int> printListFromTailToHead2(ListNode* head){
        if(head!=NULL){
            printListFromTailToHead2(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};