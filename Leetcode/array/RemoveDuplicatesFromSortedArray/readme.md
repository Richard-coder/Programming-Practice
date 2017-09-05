# 26. Remove Duplicates from Sorted Array

tags： Array，Two Pointers

---

## 题目原文
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
	
Do not allocate extra space for another array, you must do this in place with constant memory.
	
For example,
Given input array nums = [1,1,2],
	
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

## 题目大意
删除数组中重复的元素，返回删除重复元素数组的长度
要求不可新声明数组

## 解题思路
遍历数组，有连个索引值，index索引不重复的元素，i索引所有元素，将i索引元素与index元素比较，不同则放入index索引元素后，index元素按索引值排列放在数组前面

## 代码
### [c++代码](./src/cpp/RemoveDuplicatesFromSortedArray.cpp)

```c++
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};
```

