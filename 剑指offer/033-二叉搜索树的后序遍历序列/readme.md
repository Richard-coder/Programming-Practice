# 033-二叉搜索树的后序遍历序列

tags： 递归 二叉搜索树

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/024-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97](https://github.com/gatieme/CodingInterviews/tree/master/024-二叉搜索树的后序遍历序列))

### 二叉搜索树

二叉排序树或者是一棵空树，或者是具有下列性质的二叉树：

1. 若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
2. 若右子树不空，则右子树上所有结点的值均大于或等于它的根结点的值；
3. 左、右子树也分别为二叉排序树；
4. 没有键值相等的节点。

注意：左子树上所有结点的值均小于它的根结点的值

**对一棵二叉搜索树进行中序遍历（左根右）可得到一个关键字递增有序序列**

### 二叉搜索树的后序序列（左右根）特征

![äºåæåºæ ](https://github.com/gatieme/CodingInterviews/raw/master/024-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97/tree.jpg)

比如我们的这个二叉排序树

> 中序序列 2, 5, 9, 12, 15, 16, 17, 18, 19
>
> 后序序列 2, 9, 5, 16, 17, 15, 19, 18, 12

如果按照后序遍历，先左后右最后自己的顺序来遍历树，数组的最后一个元素肯定是自己（父节点），然后剩余的部分分成两个部分，第一部分都比自己小（左子树部分），第二部分都比自己大（右子树部分），因此套用这个关系就可以循环检验出是否是二叉搜索树的后序遍历了

根（最后一个节点）前面被划分为小于它（左子树）和大于它（右子树）的两部分

BST的后序序列的合法序列是

- 对于一个序列S，最后一个元素是x （也就是根）

如果去掉最后一个元素的序列为T，那么T满足：

- T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，
- 且这两段（子树）都是合法的后序序列。

完美的递归定义

## 代码

### [c++代码](./src/cpp/033-二叉搜索树的后序遍历序列.cpp)

```c++
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST_Core(sequence,0,sequence.size()-1);
    }
    bool VerifySquenceOfBST_Core(vector<int> sequence,int start,int end){
        if(sequence.empty()||start>end)
            return false;
        int i=start;
        for(;i<=end-1;i++){
            if(sequence[i]>sequence[end])
                break;
        }
        int j=i;
        for(;j<=end-1;j++){
            if(sequence[j]<sequence[end])
                return false;
        }
        bool left=true;
        if(i>start)
            left=VerifySquenceOfBST_Core(sequence,start,i-1);
        bool right=true;
        if(i<end-1)
            right=VerifySquenceOfBST_Core(sequence,i,end-1);
        return left&&right;
    }
};
```

### [python代码](./src/python/033-二叉搜索树的后序遍历序列.py)

```python

```
