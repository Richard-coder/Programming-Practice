# 025-合并两个排序的链表

tags： 链表 递归

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## 解题思路

[参考](https://cuijiahua.com/blog/2017/12/basis_16.html)

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/017-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%8E%92%E5%BA%8F%E7%9A%84%E9%93%BE%E8%A1%A8](https://github.com/gatieme/CodingInterviews/tree/master/017-合并两个排序的链表))

### 常规解法

用两个指针同步遍历两个链表，每次找到小的那个插入到新的链表中

### 递归解法

先判断输入的链表是否为空的指针。如果第一个链表为空，则直接返回第二个链表；如果第二个链表为空，则直接返回第一个链表。如果两个链表都是空链表，合并的结果是得到一个空链表。

两个链表都是排序好的，我们只需要从头遍历链表，判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归就可以轻松实现。

其实这道题跟LeetCode上一道题是一样的

[LeetCodet题解--21. Merge Two Sorted Lists（合并两个排序好的链表）](http://blog.csdn.net/gatieme/article/details/51094742)

当然他还有很多变种，比如说两个链表扩展成为K个的时候

[LeetCodet题解--23. Merge k Sorted Lists（合并K个已排序的链表）](http://blog.csdn.net/gatieme/article/details/51097730)

## 代码

### [c++代码](./src/cpp/025-合并两个排序的链表.cpp)

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* newHead=nullptr;
        if(pHead1==nullptr&&pHead2==nullptr)
            return nullptr;
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        if(pHead1->val<=pHead2->val){
            newHead=pHead1;
            newHead->next=Merge(pHead1->next,pHead2);
        }else{
            newHead=pHead2;
            newHead->next=Merge(pHead1,pHead2->next);
        }
        return newHead;
    }
};
```

### [python代码](./src/python/025-合并两个排序的链表.py)

```python

```
