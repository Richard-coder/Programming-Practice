# 80. Remove Duplicates from Sorted Array II

tags： Array，Two Pointers

---

## 题目原文
[原文网址](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)

Follow up for "Remove Duplicates":

What if duplicates are allowed at most twice?
For example,

Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.


## 题目大意
删除数组中重复的元素，但允许重复两次，返回删除重复元素后数组的长度，
要求不可新声明数组

## 解题思路
加一个变量统计重复次数

## 注意事项

判断输入数组的长度是否为空

本文c++版本的代码写的比较通用, 不仅可以处理重复两次的情况, 重复任意次都可以

## python代码知识点

```python
if not nums:
    return 0
```

```python
last,i,same=0,1,False
```

```python
if nums[i]!=nums[last] or not same:
                same=nums[last]==nums[i]
```

## 代码

### [c++代码](./src/cpp/RemoveDuplicatesFromSortedArrayII.cpp)

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
            return nums.size();
        int i=0,last=2;
        for (int index=1,temp=0;index<nums.size();index++){
            if (nums[i]!=nums[index]){
                nums[++i]=nums[index];
                temp=0;
            }
            else{
                temp++;
                if (temp<last)
                    nums[++i]=nums[index];
            }
        }
        return i+1;
        
    }
};
```

### [python代码](./src/python/RemoveDuplicatesFromSortedArrayII.py)
```python
class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        
        last,i,same=0,1,False
        while i<len(nums):
            if nums[last]!=nums[i] or not same:
                same=nums[last]==nums[i]
                last+=1;
                nums[last]=nums[i]
            i+=1
        return last+1
if __name__=="__main__":
    print Solution().removeDuplicates([1,1,1,2,2,3])
```
