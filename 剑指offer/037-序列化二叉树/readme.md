# 037-序列化二叉树

tags： 二叉树 前序遍历

---

## 题目原文

[牛客网链接](https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=4&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

请实现两个函数，分别用来序列化和反序列化二叉树

## 解题思路

其实这道题约定的序列化没有固定的格式, 只要你序列化后的结果, 再反序列化后与原树相同即可,

因此我们可以随意指定自己的格式,

比如空节点用$表示,或则#表示,

然后遍历采用先序, 中序, 后序或者层次都可以,

我们的示例程序中采用空结点用#表示, 结点与结点用逗号,分隔

选择了合适的遍历算法, 那么剩下的问题就是字符串序列和整数权值的相互转换问题

- 序列化的关键, 其实就是将树的权值(整数)转换为字符串序列, 可以采用ostringstream, sprintf和itoa
- 反序列化的关键, 则正好相反, 将字符串转换为整数, 可以使用istringstream, sscanf和atoi

这道题比较麻烦的是序列化的结果与int和char的转换

## 代码

### [c++代码](./src/cpp/037-序列化二叉树.cpp)

```c++
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == nullptr)
			return nullptr;
		string str;
		SerializeCore(root, str);
		char* res = new char[str.length() + 1];
		const char* c_str = str.c_str();
		strcpy(res, c_str);
		return res;
	}
	TreeNode* Deserialize(char *str) {
		if (!str) {
			return NULL;
		}
		TreeNode* res = DeserializeCore(&str);
		return res;
	}

	void SerializeCore(TreeNode *root, string& str) {
		if (root == nullptr) {
			str += '#';
			return;
		}
		string temp = to_string(root->val);
		str += temp;
		str += ',';
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}
	// 递归时改变了str值使其指向后面的序列，因此要声明为char**
	TreeNode* DeserializeCore(char** str) {
		// 到达叶节点时，调用两次，都返回null，所以构建完毕，返回父节点的构建
		if (**str == '#') {
			(*str)++;
			return NULL;
		}
		// 因为整数是用字符串表示，一个字符表示一位，先进行转换
		int num = 0;
		while (**str != ',' && **str != '\0') {
			num = num * 10 + ((**str) - '0');
			(*str)++;
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0') {
			return root;
		}
		else {
			(*str)++;
		}
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);
		return root;
	}
};
```

### [python代码](./src/python/037-序列化二叉树.py)

```python

```
