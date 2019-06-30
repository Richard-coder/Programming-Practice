# 80. Remove Duplicates from Sorted Array II

tags： Array，Two Pointers

---

## 题目原文
[题目链接](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

**示例 1:**

```
给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**示例 2:**

```
给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**说明:**

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

## 题目大意
删除数组中重复的元素，但允许重复两次，返回删除重复元素后数组的长度，
要求不可新声明数组

## 解题思路
加一个变量统计重复次数

## 注意事项

判断输入数组的长度是否为空

在重复两次的时候也要进行交换, 即代码中的
```
            else{
                temp++;
                if (temp<last)
                    nums[++i]=nums[index];
            }
```

至于原因用[0,0,1,1,1,1,2,3,3]作为测试用例便可知道

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
