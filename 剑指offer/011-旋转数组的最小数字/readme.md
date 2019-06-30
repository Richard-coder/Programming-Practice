# 011-旋转数组的最小数字

tags： 二分查找

---

## 题目原文
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## 解题思路
这道题最简单的解法是从头遍历数组，自然会找到数组最小的元素，时间复杂度是$\Theta(n)$,但这种方法没有用到旋转数组部分有序的特性。

考虑旋转数组的一般性质，一般情况下，最小数字的特点是左边的数字和右边的数字都比其大，所以旋转数组可以以最小数字为分界点，分为两部分：左边的数组是递增的，右边的数组是递减的，且左边的数组元素都大于右边的数组元素。因此可以采用二分查找的思想，实现$\Theta(logn)$的复杂度。

### 一般情况
先考虑一般情况：分别用两个指针指向旋转数组的第一个元素和最后一个元素，根据旋转数组的性质，第一个元素应大于或等于最后一个元素（有特例，先不考虑）。然后，观察旋转数组中间元素的值，如果中间值位于左边的递增子数组，那么中间值应该大于或等于第一个元素，所以把第一个指针指向中间元素，移动后，第一个指针仍在指向递增子数组的元素；反之，如果中间值位于右边的递减子数组，那么中间值应该小于或等于最后一个元素，所以把第二个指针指向中间元素，移动后，第二个指针仍指向递减子数组的元素。这样，不论移动的是第一个指针还是第二个指针，移动指针后，查找范围都会缩减为原来的一半。更新指针后，进行下一轮查找。

按照上面的思路进行查找，查找结束时，第一个指针指向递增子数组的最后一个元素，第二个指针指向递减子数组的第一个元素。所以查找结束时，两个指针会指向相邻的元素（查找结束条件），第二个指针指向的元素就是旋转数组的最小元素。

上述算法的不变性体现在，第一个指针永远指向递增子数组的元素，第二个元素永远指向递减子数组的元素；算法的单调性体现在每次更细指针后，查找的数组规模都会变为原来的一半。

下图显示了在数组[3 4 5 1 2]中按照上述思路查找最小数字的过程。

![查找旋转数组最小数字过程][1]
<center><small> 查找旋转数组最小数字过程</small></center>
### 特例
然而，上述思路只考虑了一般情况，没有考虑特例。

(1) 当数组未发生旋转时：即将原数组前0个元素移动到后面，仍符合旋转数组的定义，但此时第一个元素小于或等于最后一个元素，且第一个元素就是最小值，此时直接返回第一个元素的值即可。所以middle的初始值为start.

(2) 首末元素与中间元素相等时：由于首末元素与中间元素相等，无法判断中间元素属于递增子数组还是递减子数组,也就无法移动指针来改变查找范围，这种情况只能改用顺序查找。

下图中的[1 0 1 1 1]和[1 1 1 0 1]都可以看成数组[0 1 1 1 1]的旋转。两个数组的首末值和中间值都是1，但左边的数组中间值位于递减子数组，右边的数组位于递增子数组。因此，这种情况下无法移动指针，减小查找范围。

### 解题


## 代码
### [c++代码](./src/cpp/011-旋转数组的最小数字.cpp)

下面的代码书写方式保证了除了上面提到的特例, 也可以处理[0], [5 5 5 4 3 5]这样的输入

```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int start=0,end=rotateArray.size()-1;
        int middle=start;
        while(rotateArray[start]>=rotateArray[end]){
            if(end-start==1){
                middle=end;
                break;
            }
            middle=(start+end)>>1;
            if(rotateArray[start]==rotateArray[middle]&&rotateArray[start]==rotateArray[end]){
                return MinInorder(rotateArray);
            }
            if(rotateArray[middle]>=rotateArray[start])
                start=middle;
            else if(rotateArray[middle]<=rotateArray[end])
                end=middle;
        }
        return rotateArray[middle];
    }
    int MinInorder(vector<int> rotateArray){
        int result=rotateArray[0];
        for(int i=1;i<rotateArray.size();i++){
            if(result>rotateArray[i])
                return rotateArray[i];
        }
        return result;
    }
};
```

### [python代码](./src/python/011-旋转数组的最小数字.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray) == 0:
            return 0
        front = 0
        rear = len(rotateArray) - 1
        mid = front
        while rotateArray[front] >= rotateArray[rear]:
            if rear - front == 1:
                mid = rear
                break
            mid = (front + rear) // 2
            if rotateArray[front] == rotateArray[mid] and rotateArray[mid] == rotateArray[rear]:
                return self.minInOrder(rotateArray, front, rear)

            if rotateArray[mid] >= rotateArray[front]:
                front = mid
            elif rotateArray[mid] <= rotateArray[rear]:
                rear = mid

        return rotateArray[mid]

    def minInOrder(self, rotateArray, front, rear):
        minNum = rotateArray[front]
        for temp in rotateArray[front:rear + 1]:
            if minNum >= temp:
                minNum = temp
        return minNum
```

[1]:./img/查找旋转数组最小数字过程.png

### 扩展

书里p80有快速排序的代码