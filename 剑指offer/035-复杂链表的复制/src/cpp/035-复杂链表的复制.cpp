/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
    
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* node=pHead;

        while(node!=nullptr){
            RandomListNode* cloneNode=new RandomListNode(0);
            cloneNode->label=node->label;
            cloneNode->next=node->next;
            cloneNode->random=nullptr;
            node->next=cloneNode;
            node=cloneNode->next;
        }
    }
    
    void ConnectRandomNodes(RandomListNode* pHead){
        RandomListNode* node=pHead;
        RandomListNode* cloneNode=node->next;
        
        while(node!=nullptr){
            if(node->random!=nullptr){
                cloneNode->random=node->random->next;
            }
            node=cloneNode->next;
            cloneNode=node->next;
        }
    }
    
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* node=pHead;
        RandomListNode* cloneHead=nullptr;
        RandomListNode* cloneNode=nullptr;
        
        cloneNode=cloneHead=node->next;
        node->next=cloneNode->next;
        node=cloneNode->next;
        
        while(node!=nullptr){
            cloneNode->next=node->next;
            cloneNode=node->next;
            node->next=cloneNode->next;
            node=node->next;
        }
        
        return cloneHead;
    }
};