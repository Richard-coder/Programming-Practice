# 链表 从尾到头打印链表

tags： 链表

---

## 题目原文
题目描述

    输入一个链表，从尾到头打印链表每个节点的值。
输入描述:

    输入为链表的表头
输出描述:

    输出为需要打印的“新链表”的表头

## 解题思路
从头到尾遍历链表，将链表的值依次放入栈中，遍历完成后再依次从栈顶输出每个节点

因为递归的本质在于栈就够，因此也可以用递归完成本题。访问一个节点时，先递归输出其子节点，再输出其自身
## 代码
### [c++代码](./src/cpp/从尾到头打印链表.cpp)

```c++
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
```

### [python代码](./src/python/从尾到头打印链表.py)

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead2(self, listNode):
        # write code here
        if not listNode:
            return []
        res=[]
        head=listNode
        while head:
            res.insert(0,head.val)
            head=head.next
        return res
    def printListFromTailToHead(self, listNode,res=None):
        if res==None:
            res=[]
        if not listNode:
            return []
        else:
            self.printListFromTailToHead(listNode.next,res)
            res.append(listNode.val)
        return res
```
