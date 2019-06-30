# 017-打印1到最大的n位数

tags： 大数 全排列

---

## 题目原文

[牛客网链接 暂无]()

**题目描述**

> 给定一个数字N，打印从1到最大的N位数。

**输入**

> 每个输入文件仅包含一组测试样例。
>
> 对于每个测试案例，输入一个数字N(1<=N<=5)。 **输出** 对应每个测试案例，依次打印从1到最大的N位数。

**样例输入**

> 1

**样例输出**

> 1 2 3 4 5 6 7 8 9

## 解题思路

[参考]([https://github.com/gatieme/CodingInterviews/tree/master/012-%E6%89%93%E5%8D%B01%E5%88%B0%E6%9C%80%E5%A4%A7%E7%9A%84N%E4%BD%8D%E6%95%B0](https://github.com/gatieme/CodingInterviews/tree/master/012-打印1到最大的N位数))

### 最简单的解法--跳进面试官的陷阱

好像没有什么问题，但是仔细分析你就会发现，N的范围并不确定，我们没法保证这些数是不是超出了INT_MAX的表示范围。

```c++
class Solutin
{
public :
    void Print(int n)
    {
        int max = pow(10, n);
        for(int i = 1; i < max; i++)
        {
            cout <<i <<endl;
        }
    }

};
```



当n过大的时候，就会溢出，这时候我们的程序输出的值是不确定或者说是被截断的

### 用字符串解决大数问题

我们的思路是：

- 用字符串表达大数。'0'-'9'，因为是N位的数，用N+1的字符串存储，最后一位保存结束符'\0'，前半部分补零。
- 用字符串模拟数字的自增，进位，输出
- 当串长度超过N+1时，或者第0位产生进位时就溢出

```c++
// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}
```



### 递归--转换为数字排列的解法

上面的算法已经很不错了，但是代码复杂，要在短时间内完成这样思路清晰而缜密的代码有点困难，因此我们需要更加简洁的方法

> 如果我们在数字前面补上0的话，那么我们发现，n位所有的十进制数起始就是n个从0到9的全排列。
>
> 也就是说，我们把数字的每一位都从0到9排列一遍，就得到了所有的十进制数。

只要我们在打印的时候，数字排在前面的0不用打印出来而已。

- 全排列用递归很容易表示，数字的每一位都可能是0~9中的一个数，然后设置下一位。
- 递归结束的条件是我们已经设置了数字的最后一位

```c++
// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}
```

## 相关题目

前面的代码中，我们都是用一个char型字符表示十进制数字的一位。 8个bit的char型字符最多能表示256个字符，而十进制数字只有0-9的10个数字。 因此用char型字符串来表示十进制的数字并没有充分利用内存，有一些浪费。 有没有更高效的方式来表示大数。 

可以使用**bitmap算法**，这个很有意思。特别是在数据量大的时候，非常高效
所谓bitmap就是用一个bit位来标记某个元素对应的value，而key即是这个元素。由于采用bit为单位来存储数据，因此在可以大大的节省存储空间。

十进制表示方法，不止一种
ASCII
BCD
压缩BCD
这些都是十进制编码，其中压缩BCD可以多存储一倍的数据
其他，
16Bits 可以表示万进制
32Bits 可以表示亿进制，10   亿进制
这些和十进制优势关系密切的表示方法，转换简单
另外一种 多 字节（字，双字，四字）串 表示方法，
是 二进制表示法，
和十进制转换不太方便，不过+，-，*，/ 等数学运算，实现方便.

## 代码

### [c++代码](./src/cpp/017-打印1到最大的n位数.cpp)

```c++
/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <cstdio>
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);
	system("pause");
	return 0;
}

```

### [python代码](./src/python/017-打印1到最大的n位数.py)

```python

```

## 举一反三

