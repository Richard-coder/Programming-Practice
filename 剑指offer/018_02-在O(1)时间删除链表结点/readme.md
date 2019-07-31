# 018_02-在O(1)时间删除链表结点

tags： 链表

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。

例如，链表1->2->3->3->4->4->5

处理后为 1->2->5

## 解题思路

我们的思路是，

1. 我们每次都判断当前结点的值与下一个节点的值是否重复
2. 如果重复就循环寻找下一个不重复的节点，　将他们链接新新链表的尾部（其实就是删除重复的节点）

## 代码

### [c++代码](./src/cpp/018_02-在O(1)时间删除链表结点.cpp)

```c++
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
```

### [python代码](./src/python/018_02-在O(1)时间删除链表结点.py)

```python

```
