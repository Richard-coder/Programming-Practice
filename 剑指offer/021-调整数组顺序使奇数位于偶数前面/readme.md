# 021-调整数组顺序使奇数位于偶数前面

tags： 稳定排序 两指针

---

## 剑指offer题目 不要求稳定

### 题目原文

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

### 解题思路

由于题目中只要求记奇数在偶数之前，那么我们在扫描这个数组的时候，如果发现一个偶数出现在奇数之前就交换他们的位置，这样一趟后就满足要求了。

因此我们

- 维护两个索引或者指针，一个指向数组的第一个元素，并向后移动，一个指向数组的最后一个元素，并向前移动。
- 如果第一个指针指向的元素是偶数，而第二个指针指向的元素是奇数，说明偶数在奇数前面，那么就交换这两个数。
- 直到两个指针相遇为止

```c++
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        vector<int>::iterator left = array.begin( );
        vector<int>::iterator right = array.end( ) - 1;

        // 三种顺序容器中只有deque和vector容器的迭代器支持大小的比较和算术运算。

        while(left < right)
        {

            //  left向后移动指向第一个偶数
            while(left < right && (*left & 0x01) == 1)
            {
                left++;
            }

            // right向前移动指向第一个奇数
            while(left < right && (*right &0x01) == 0)
            {
                right--;
            }

            if(left < right)
            {
                swap(*left, *right);
            }
        }

    }
```

## 牛客网题目

[题目链接](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

### 题目原文

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

与剑指offer题目不同的是, 这道题要求`奇数和奇数，偶数和偶数之间的相对位置不变`, 类似于排序中的稳定性

### 稳定性定义

算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！

### 解题思路1 使用稳定排序算法

从题目得出的信息：

相对位置不变--->保持稳定性；奇数位于前面，偶数位于后面 --->存在判断，挪动元素位置；

这些都和内部排序算法相似，考虑到具有稳定性的排序算法不多，例如插入排序，归并排序等；

采用冒泡排的思想实现:

每次循环前偶后奇就交换,  同时我们设立一个标识，来标识数组是否已经符合要求

当再次循环时，发现没有要交换的数据，说明数组已经符合要求

```c++
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        bool isSwap = false;
        for (int i = 0; i < array.size( ); i++)
        {
            isSwap = false;
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                    isSwap = true;
                }
            }
            if(isSwap == false)
            {
                break;
            }
        }


    }
```



采用插入排的思想实现:

```c++
public class Solution {
    public void reOrderArray(int [] array) {
        //相对位置不变，稳定性
        //插入排序的思想
        int m = array.length;
        int k = 0;//记录已经摆好位置的奇数的个数
        for (int i = 0; i < m; i++) {
            if (array[i] % 2 == 1) {
                int j = i;
                while (j > k) {//j >= k+1
                    int tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                    j--;
                }
                k++;
            }
        }
    }
}
```



### 思路2 辅助数组完成

我们也可以利用一个辅助的数组空间来实现

- 在原来的数组中遇到偶数就放进新数组中，然后将该偶数从原来数组中删除，当整个遍历结束后，原来数组中只剩下奇数，新的数组总只剩下偶数，最后我们将新的数组追加在原来数组的末尾即可

```c++
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }

        vector<int> array_temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();


        for (; ib1 != array.end();)
        {            //遇见偶数，就保存到新数组，同时从原数组中删除
            if (*ib1 % 2 == 0)
            {
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else{
                ib1++;
            }

        }
        vector<int>::iterator ib2, ie2;
        ib2 = array_temp.begin();
        ie2 = array_temp.end();

        for (; ib2 != ie2; ib2++)             //将新数组的数添加到老数组
        {
            array.push_back(*ib2);
        }
    }
```

### 思路3 STL

STL　stable_partition 这个函数

函数功能是将数组中　isOk为真的放在数组前，假的放在数组后，和题意相符

````c++
stable_partition(array.begin(), array.end(), [](int i){return i % 2 == 1;});
````



## 代码

### [c++代码](./src/cpp/021-调整数组顺序使奇数位于偶数前面.cpp)

```c++
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        bool isSwap = false;
        for (int i = 0; i < array.size( ); i++)
        {
            isSwap = false;
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                    isSwap = true;
                }
            }
            if(isSwap == false)
            {
                break;
            }
        }


    }
```

### [python代码](./src/python/021-调整数组顺序使奇数位于偶数前面.py)

```python

```
