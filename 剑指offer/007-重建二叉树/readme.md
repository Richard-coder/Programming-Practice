# 007-重建二叉树

tags： 二叉树

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

## 解题思路

### 遍历
二叉树的遍历一般有一下几种方式：

 + 前序遍历：根左右
 + 中序遍历：左根右
 + 后序遍历：左右根
 + 层次遍历：按层遍历

![二叉树遍历][1]
<center><small> 二叉树遍历</small></center>
### 解题
二叉树前序遍历的第一个节点即为根节点，在中序遍历中根据根节点的位置可以划分出左右子树，然后再前序遍历中找到左右子树。
在找到了左右子树的前序遍历和中序遍历后，进行递归即可。

注意：这道题需要对输入进行判断，默认原二叉树节点的值不重复

## 代码
### [c++代码](./src/cpp/007-重建二叉树.cpp)

```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        // 判断输入是否合法
        if(pre.empty()||vin.empty()||pre.size()!=vin.size()) 
            throw std::logic_error("Invalid Input");
        return ReconstructCore(pre,vin);
    }
    TreeNode* ReconstructCore(vector<int> pre,vector<int> vin){
        // 两个序列长度不相等, 报错
        if(pre.size()!=vin.size())
            throw std::logic_error("Invalid Input");
        // 输入序列长度为0, 空子树,返回空指针
        int length=pre.size();
        if(pre.size()==0)
           return nullptr;
        // 获取根节点的值,如果序列长度为1,说明此时根节点已经是叶子节点了, 返回根节点
        TreeNode* root=new TreeNode(pre[0]);
        if(length==1){
            if(pre[0]==vin[0])
                return root;
            else
                throw std::logic_error("Invalid Input");
        }
        // 在中序遍历中找到根节点的位置
        int rootIndex=0;
        for(;rootIndex<length;rootIndex++){
            if(vin[rootIndex]==pre[0]){
                break;
            }
        }
        // 中序遍历序列中没找到根节点, 报错
        if(rootIndex>=length)
            throw std::logic_error("Invalid Input");
        // 计算左右子树的值
        int leftLength=rootIndex, rightLength=length-1-rootIndex;
        // 初始化左右子树两种遍历序列的容器,长度为0时。则初始化为空的容器
        vector<int> preLeft(leftLength),preRight(rightLength);
        vector<int> vinLeft(leftLength),vinRight(rightLength);
        for(int i=0;i<length;i++){
            if(i<rootIndex){
                preLeft[i]=pre[i+1];// 注意这个是pre[i+1]
                vinLeft[i]=vin[i];
            }
            if(i>rootIndex)
            {
                preRight[i-rootIndex-1]=pre[i];
                vinRight[i-rootIndex-1]=vin[i];
            }
        }
        // 递归调用
        root->left=ReconstructCore(preLeft,vinLeft);
        root->right=ReconstructCore(preRight,vinRight);
        return root;
        }
};
```



### [python代码](./src/python/007-重建二叉树.py)

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        #判断两个输入序列是否为空
        if not pre and not tin:
            return None
        #将list转为set，判断两个输入序列的元素是否相同
        if set(pre)!=set(tin):
            return None
        root =TreeNode(pre[0])
        #index()方法返回查找对象的索引位置，如果没有找到对象则抛出异常。
        index = tin.index(pre[0])
        root.left=self.reConstructBinaryTree(pre[1:index+1],tin[0:index])
        root.right=self.reConstructBinaryTree(pre[index+1:],tin[index+1:])
        return root
```

[1]:./img/二叉树遍历.png