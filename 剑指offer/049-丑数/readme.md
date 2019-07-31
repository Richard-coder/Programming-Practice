# 049-丑数

tags：空间换时间

---

## 题目原文

[牛客网链接]()



## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/034-%E4%B8%91%E6%95%B0](https://github.com/gatieme/CodingInterviews/tree/master/034-丑数))

### 暴力方法

最简单直接的方法，就是**逐个判断每个整数是不是丑数**，循环所有数字，判断它是不是丑数 首先我们需要判断某个整数number是不是丑数

```
bool IsUglyNumber(int number)
{
    while(number % 5 == 0)
    {
        number /= 5;
    }

    while(number % 3 == 0)
    {
        number /= 3;
    }

    while(number % 2 == 0)
    {
        number /= 2;
    }

    return (number == 1);
}
```

然后接下来，就是按照顺序判断每一个整数是不是丑数

```
int GetUglyNumber_Solution(int index)
{
    if(index <= 0)
    {
        return -1;
    }

    int count = 1;
    int num = 0;

    while(count <= index)
    {
        num++;
        if(IsUglyNumber(num) == 1)
        {
            debug <<"count = "<<count <<", " <<num <<" is " <<endl;
            count++;
        }
    }

    return num;
}
```

### 寻找所有的丑数

根据丑数的定义，丑数应该是另一个丑数乘以2、3或者5的结果（1除外）。 因此我们可以创建一个数组，里面的数字是排好序的丑数。里面的每一个丑数是前面的丑数乘以2、3或者5得到的。那关键就是确保数组里的丑数是有序的了。 我们假设数组中已经有若干个丑数，排好序后存在数组中。我们把现有的最大丑数记做M。 现在我们来生成下一个丑数，该丑数肯定是前面某一个丑数乘以2、3或者5的结果。 我们首先考虑把已有的每个丑数乘以2。在乘以2的时候，能得到若干个结果小于或等于M的。由于我们是按照顺序生成的，小于或者等于M肯定已经在数组中了，我们不需再次考虑； 我们还会得到若干个大于M的结果，但我们只需要第一个大于M的结果，因为我们希望丑数是按从小到大顺序生成的，其他更大的结果我们以后再说。 我们把得到的第一个乘以2后大于M的结果，记为M2。同样我们把已有的每一个丑数乘以3和5，能得到第一个大于M的结果M3和M5。那么下一个丑数应该是M2、M3和M5三个数的最小者。

```c++
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        vector<int> ugly(index);
        ugly[0]=1;
        int idx2=0,idx3=0,idx5=0,idx=1,val;
        
        while(idx<index){
            val=min(ugly[idx2]*2,min(ugly[idx3]*3,ugly[idx5]*5));
            if(val==ugly[idx2]*2) //将产生这个丑数的index*向后挪一位；
                idx2++;
            if(val==ugly[idx3]*3)//这里不能用elseif，因为可能有两个最小值，这时都要挪动；
                idx3++;
            if(val==ugly[idx5]*5)
                idx5++;
            ugly[idx++]=val;
        }
        
        return ugly[index-1];
    }
};
```



## 代码

### [c++代码](./src/cpp/049-丑数.cpp)

```c++
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        vector<int> ugly(index);
        ugly[0]=1;
        int idx2=0,idx3=0,idx5=0,idx=1,val;
        
        while(idx<index){
            val=min(ugly[idx2]*2,min(ugly[idx3]*3,ugly[idx5]*5));
            if(val==ugly[idx2]*2) //将产生这个丑数的index*向后挪一位；
                idx2++;
            if(val==ugly[idx3]*3)//这里不能用elseif，因为可能有两个最小值，这时都要挪动；
                idx3++;
            if(val==ugly[idx5]*5)
                idx5++;
            ugly[idx++]=val;
        }
        
        return ugly[index-1];
    }
};
```

### [python代码](./src/python/049-丑数.py)

```python

```
