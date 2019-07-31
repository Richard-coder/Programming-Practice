# 022-链表中倒数第k个结点

tags： 两支针

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个链表，输出该链表中倒数第k个结点。

## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/015-%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E7%BB%93%E7%82%B9](https://github.com/gatieme/CodingInterviews/tree/master/015-链表中倒数第k个结点))

这道题我想大多数人都会有思路，因为我们已经见的很多了 最暴力的方式,两趟遍历，第一趟先求出list的长度length，然后进而length - k得到倒数第k个节点的位置 当然我们大多数都会知道另外一个更加高效的方法，**双指针法** 其实就是第一个指针right先向前走K步，然后left和right一起走，此时两个指针差别K步，那么当right走到链表尾部的时候，left指向的就是倒数第K个节点

期间要注意的问题有

- 链表可能为NULL
- 链表长度可能没有K个
- 输入参数k是unsigned int,当k为0时,  for循环中k-1得到的不是-1, 而是4294967295(无符号的0XFFFFFFFF), for循环次数会超出预计, 造成程序崩溃. 

```c++
/// 1 -> 2 -> 3 -> 4 -> 5
/// 比如要走倒数第3个节点
/// 那么right先走到第3 - 1个节点&[2]
/// 那么right指针向前走到其下一个节点为NULL时, left节点既是倒数第K个节点
///  此时两个指针相差为K - 1


/// 1 -> 2 -> 3 -> 4 -> 5
/// 比如要走倒数第3个节点
/// 那么right先走到第3个节点&[2]
/// 那么right指针向前走到链表尾部为NULL时, left节点既是倒数第K个节点
/// 此时两个指针相差为K
class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == NULL)
        {
            return NULL;
        }
        unsigned int i = 0;
        ListNode *right = pListHead;

        //  left指针先向前走K步
        while(i < k && right != NULL)
        {
            debug <<"index  = " <<i <<", value = " <<right->val <<endl;
            right = right->next;
            i++;
        }

        if(right == NULL && i < k)
        {
            cout <<"the list length = " <<i <<" < " <<k <<endl;
            return NULL;
        }

        ListNode *left = pListHead;
        while(right != NULL)
        {
            debug <<"index  = " <<i++ <<", value = " <<right->val <<endl;

            left = left->next;
            right = right->next;
        }

        return left;

    }
};
```

当然也可以第一个指针right先向前走K-1步，然后left和right一起走，此时两个指针差别K-1步，那么当right走到链表尾部的前一个结点时候的，left指向的就是倒数第K个节点

```c++
/// 1 -> 2 -> 3 -> 4 -> 5
/// 比如要走倒数第3个节点
/// 那么right先走到第3 - 1个节点&[2]
/// 那么right指针向前走到其下一个节点为NULL时, left节点既是倒数第K个节点
/// 此时两个指针相差为K - 1
/// 因此right需要走到链表尾部前一个结点


/// 1 -> 2 -> 3 -> 4 -> 5
/// 比如要走倒数第3个节点
/// 那么right先走到第3个节点&[2]
/// 那么right指针向前走到链表尾部为NULL时, left节点既是倒数第K个节点
/// 此时两个指针相差为K
/// 因此right需要走到链表尾部前

class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == NULL)
        {
            return NULL;
        }
        unsigned int i = 0;
        ListNode *right = pListHead;

        //  left指针先向前走K - 1步
        while(i < k - 1 && right != NULL)
        {
            debug <<"index  = " <<i <<", value = " <<right->val <<endl;
            right = right->next;
            i++;
        }

        if(right == NULL)
        {
            cout <<"the list length = " <<i <<" < " <<k <<endl;
            return NULL;
        }

        ListNode *left = pListHead;
        while(right->next != NULL)
        {
            debug <<"index  = " <<i++ <<", value = " <<right->val <<endl;

            left = left->next;
            right = right->next;
        }

        return left;

    }
};
```

### c++知识点

切勿混合使用带符号类型和无符号类型，因为混合使用有符号类型和无符号类型常常导致与我们期望值大相径庭的结果

**当我们给一个无符号类型赋一个超过其表示范围的负值时，其最后的结果是该负值与该无符号类型所能表示的数的总个数的和，如果所得结果还是一个不在此类型表示范围的负数，则将所得结果重复以上相加的过程，直到最后得到一个在其表示范围的数，此即为最后的结果**

**当我们赋给一个无符号类型一个超出它表示范围的 正值 时，结果是将我们所赋的这个值对此无符号类型所能表示的数的总个数取模后的余数**

当算术表达式中既有**无符号数**又有**带符号数**时，那么在进行运算之前，这个**带符号数值会先被转换成无符号数**

**当我们给带符号类型赋予一个超过其表示范围的值时，其结果是未定义的**

**事实上**，只有两个类型相同的对象才能进行运算。当两个对象的数据类型不一致时，低精度的一方会尝试主动转换成与高精度的一方一样的类型，然后再进行运算。

### 相关题目

![1562038903131](img/readme.assets/1562038903131.png)

## 代码

### [c++代码](./src/cpp/022-链表中倒数第k个结点.cpp)

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
```

### [python代码](./src/python/022-链表中倒数第k个结点.py)

```python

```

