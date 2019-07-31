# 045-把数组排成最小的数

tags： 排序

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/033-%E6%8A%8A%E6%95%B0%E7%BB%84%E6%8E%92%E6%88%90%E6%9C%80%E5%B0%8F%E7%9A%84%E6%95%B0](https://github.com/gatieme/CodingInterviews/tree/master/033-把数组排成最小的数))

首先因为数组可能非常长，所以要定义一个整数类，使得其大小可以容纳所有的数组元素组成的数不大现实。因此我们直接输出这个数组，让其看起来像一个整数，这样我们就可以把问题转化为：如何给这个数组排序，使其看做一个数字的时候最小。 第一个想到的可能是按字典序排序，小的在前面。可惜这个是不可行的，比如32的字典序比322小，但是32322比32232大， 所以在这里自定义一个比较大小的函数，比较两个字符串s1, s2大小的时候，先将它们拼接起来，比较s1+s2,和s2+s1那个大，如果s1+s2大，那说明s2应该放前面，所以按这个规则，s2就应该排在s1前面。

思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。如果ab < ba，则a < b；如果ab > ba，则a > b；如果ab = ba，则a = b。比较函数的定义是本解决方案的关键。这道题其实就是希望我们能找到一个排序规则，根据这个规则排出来的数组能排成一个最小的数字。

## 知识点

### sort函数

> [sort函数用法详解](https://blog.csdn.net/qq_41785863/article/details/81128146)
>
> [详细解说 STL 排序(Sort)](http://www.cppblog.com/mzty/archive/2005/12/15/1770.aspx)

用于C++中，对给定区间所有元素进行排序。头文件是#include <algorithm>

sort函数进行快速排序，时间复杂度为n*log2n，比冒泡之类的要省时不少

Sort函数使用模板:

Sort(start,end,排序方法)

1.第一个参数是要排序数组的起始地址

2.第二个参数是数组结束地址的下一位

3.第三个是排序的方法，可不填，默认升序

如果你需要自己定义比较函数，你可以把你定义好的仿函数(functor)作为参数传入。每种算法都支持传入比较函数。以下是所有STL sort算法函数的名字列表:

| [函数名](http://www.stlchina.org/twiki/bin/view.pl/Main/STLSortAlgorithms?sortcol=0&table=1&up=0#sorted_table) | [功能描述](http://www.stlchina.org/twiki/bin/view.pl/Main/STLSortAlgorithms?sortcol=1&table=1&up=0#sorted_table) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| sort                                                         | 对给定区间所有元素进行排序                                   |
| stable_sort                                                  | 对给定区间所有元素进行稳定排序                               |
| partial_sort                                                 | 对给定区间所有元素部分排序                                   |
| partial_sort_copy                                            | 对给定区间复制并排序                                         |
| nth_element                                                  | 找出给定区间的某个位置对应的元素                             |
| is_sorted                                                    | 判断一个区间是否已经排好序                                   |
| partition                                                    | 使得符合某个条件的元素放在前面                               |
| stable_partition                                             | 相对稳定的使得符合某个条件的元素放在前面                     |

其中nth_element 是最不易理解的，实际上，这个函数是用来找出第几个。例如：找出包含7个元素的数组中排在中间那个数的值，此时，我可能不关心前面，也不关心后面，我只关心排在第四位的元素值是多少。



#### 1.2 sort 中的比较函数

当你需要按照某种特定方式进行排序时，你需要给sort指定比较函数，否则程序会自动提供给你一个比较函数。

```
vector < int > vect;
//...
sort(vect.begin(), vect.end());
//此时相当于调用
sort(vect.begin(), vect.end(), less<int>() );

```

上述例子中系统自己为sort提供了less仿函数。在STL中还提供了其他仿函数，以下是仿函数列表:

| [名称](http://www.stlchina.org/twiki/bin/view.pl/Main/STLSortAlgorithms?sortcol=0&table=2&up=0#sorted_table) | [功能描述](http://www.stlchina.org/twiki/bin/view.pl/Main/STLSortAlgorithms?sortcol=1&table=2&up=0#sorted_table) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| equal_to                                                     | 相等                                                         |
| not_equal_to                                                 | 不相等                                                       |
| less                                                         | 小于                                                         |
| greater                                                      | 大于                                                         |
| less_equal                                                   | 小于等于                                                     |
| greater_equal                                                | 大于等于                                                     |

需要注意的是，这些函数不是都能适用于你的sort算法，如何选择，决定于你的应用。另外，不能直接写入仿函数的名字，而是要写其重载的()函数：

```
less<int>()
greater<int>()
```

当你的容器中元素时一些标准类型（int float char)或者string时，你可以直接使用这些函数模板。但如果你时自己定义的类型或者你需要按照其他方式排序，你可以有两种方法来达到效果：一种是自己写比较函数。另一种是重载类型的'<'操作赋

### 在类的成员函数使用带谓词的sort（）函数

> [在类的成员函数使用带谓词的sort（）函数](https://blog.csdn.net/qf1028622561/article/details/75150998)

sort()函数接受二元谓词，但是在类内定义的myCompare函数作为成员函数，实际上有三个参数，this指针、m、n。 
解决方案： 
1、将myCompare()函数挪到类定义的外面，即改为非成员函数； 
2、将myCompare()函数定义为静态成员函数，没有this指针。 

3、将myCompare()函数定义为类的友元函数，但是此时必须在类外声明该函数，否则，即使在类内定义了该友元函数，该函数仍然是不可见的。

### to_string

按照C++11的标准，to_string函数对每个基础算术类型均有重载函数

这个函数也可以自己写

```c++
template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  创建一个流

    oss <<t;            //  把值传递如流中
    return oss.str( );  //  获取转换后的字符转并将其写入result
}

```



## 代码

### [c++代码](./src/cpp/045-把数组排成最小的数.cpp)

```c++
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res="";
        int length=numbers.size();
        if(length<=0)
            return res;
        vector<string> temp(length);
        for(int i=0;i<length;i++)
            temp[i]=to_string(numbers[i]);
        
        sort(temp.begin(),temp.end(),compare);
        
        for(int i=0;i<length;i++)
            res=res+temp[i];
        
        return res;
       
    }
    
    static bool compare(const string& str1,const string& str2){
        string s1=str1+str2;
        string s2=str2+str1;
        return s1<s2;
    }
};
```

### [python代码](./src/python/045-把数组排成最小的数.py)

```python

```
