# 003-数组中重复的数字

tags： 数组

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3)

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

**样例输入**

> 2, 3, 1, 0, 2, 5, 3
>
> 2, 1, 3, 1, 4

**样例输出**

> 2
>
> 1

## 解题思路

### 一般解法

简单方法是把输入数组排序, 从排序好的数组中找到重复数字很容易.排序一个长度为$n$的数组需要$O(nlogn)$的时间

还可以用哈希表, 从头到尾扫描数组中的每个数字, 每扫描到一个数字的时候都可以用$O(1)$的时间来判断哈希表里是否已经包含了该数字.如果哈希表里没有这个数字, 就把它加入哈希表, 如果哈希表中已经存在该数字, 那么就找到一个重复的数字. 这种解法时间复杂度是$O(n)$, 但提高时间效率的代价是以一个大小为$O(n)$的哈希表为代价.

### 较好解法

这种解法充分利用数组中的数字都在$0 \sim n-1$ 的条件, 可以达到$O(n)$的时间复杂度和$O(1)$的空间复杂度

我们考虑如果每个数字都置出现一次，那么此时是最完美的，每一个下标i对应元素numbers[i]，也就是说我们对于数组中的每个元素numbers[i]都把它放在自己应该在的位置上numbers[numbers[i]]上, 如果我们发现有两个元素想往同一个位置上放的时候，说明此元素必然重复

即如下的过程

1. 如果numbers[i] == i, 那么我们认为number[i]这个元素是在自己的位置上的
2. 否则的话, numbers[i]这个元素就应该在numbers[numbers[i]]这个位置上, 于是我们交换numbers[i]和numbers[numbers[i]]
3. 重复操作1, 直到number[i]== i, 则继续操作下一个位置的元素, 或者numbers[i] == numbers[numbers[i]，元素重复

需要注意的是这种解法的前提是数组中的数字在0~n-1内.

## 代码

### [c++代码](./src/cpp/003-数组中重复的数字.cpp)

```c++
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers==nullptr) return false;
        // 这种解法的前提是数组中的数字在0~n-1内 
        for(int i=0;i<length;i++){
            if (numbers[i]<0||numbers[i]>length-1){
                return false;
            }
        }
        
        for(int i=0;i<length;i++){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]]){
                    *duplication=numbers[i];
                    return true;
                }
                int temp;
                temp=numbers[i];
                numbers[i]=numbers[temp];
                numbers[temp]=temp;
            }
        }
        
        return false;
    }
};
```

### [python代码](./src/python/003-数组中重复的数字.py)

```python

```

## 举一反三

### 题目

在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的输出是重复的数字2或者3。

### 知识点

解法二中的二分查找的写法值得学习, 包括中间值计算, 收尾指针的更新, 结束条件判断等

### 思路

#### 解法1

这道题要求不能修改输入的数组, 所以可以创建一个长度为n+1的辅助数组, 逐一把原数组的数字复制到辅助数组, 如果原数组中的数字是m, 则将其复制到辅助数组的下标为m的位置, 这样很容易就可以发现那些数字是重复的.这种解法的空间复杂度是$O(n)$, 时间复杂度也是$O(n)$

#### 解法2

采用二分法查找，时间复杂度为 $O(nlogn)$, 空间复杂度$O(1)$

如果数组中有重复的数，那么n+1个0~n范围内的数中，一定有几个数的个数大于1。那么，我们可以利用这个思路解决该问题。

我们把从1~n的数字从中间的数字m分为两部分，前面一半为1~m，后面一半为m+1~n。如果1~m的数字的数目等于m，则不能直接判断这一半区间是否包含重复的数字，反之，如果大于m，那么这一半的区间一定包含重复的数字；如果小于m，另一半m+1~n的区间里一定包含重复的数字。接下来，我们可以继续把包含重复的数字的区间一分为二，直到找到一个重复的数字。

由于如果1~m的数字的数目等于m，则不能直接判断这一半区间是否包含重复的数字，我们可以逐步减少m，然后判断1~m之间是否有重复的数，即，我们可以令m=m-1，然后再计算1~m的数字的数目是否等于m，如果等于m，再令m=m-1，如果大于m，则说明1~m的区间有重复的数，如果小于m，则说明m+1~n有重复的数，不断重复此过程。

如果输入长度为n的数组，那么函数countRange最多将被调用O(logn)次，每次需要O(n)的时间，因此总的时间复杂度是O(nlogn)。

这种解法不能保证能找到所有的重复数字


**代码**

```
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int getDuplication(const int* numbers, int length)
{
    if (numbers==nullptr||length<=0) return -1;

    int start=1, end=length-1;

    while(start<=end){
        int middle=((end-start)>>1)+start;
        int count=countRange(numbers,length,start, middle);
        if(end==start){
            if(count>1)
                return start;
            else
                return -1;
        }
        if(count>(middle-start+1))
            end=middle;
        else
            start=middle+1;
    }
    return -1;
}

int countRange(const int* numbers,int length, int start, int end){
    if (numbers==nullptr) return 0;
    int count=0;
    for(int i=0;i<length;i++){
        if(numbers[i]>=start&&numbers[i]<=end)
            count++;
    }

    return count;
}
```



