# 024-反转链表

tags： 链表

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个链表，反转链表后，输出链表的所有元素。

## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/016-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8](https://github.com/gatieme/CodingInterviews/tree/master/016-反转链表))

三指针滑动pPrev -> pNode -> pNext;

通常我们想到的就是单个指针同时滑动 比如当前节点pNode所处的位置如下

> pPrev -> pNode -> pNext; 我们先保存原来的下一个指针位置，要不然翻转后其next会指向pPrev，从而丢失指向pNext的指针 接着反转指针， 然后下面指针同步后移，以便处理后面的指针

```
pNext = pNode->next;        //  保存其下一个节点
pNode->next = pPrev;        //  指针指向反转
// 下面开始指针的后移
pPrev = pNode;              //  保存前一个指针
pNode = pNext;              //  递增指针, 指向下一个结点
```



## 代码

### [c++代码](./src/cpp/024-反转链表.cpp)

```c++
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
```

### [python代码](./src/python/024-反转链表.py)

```python

```

