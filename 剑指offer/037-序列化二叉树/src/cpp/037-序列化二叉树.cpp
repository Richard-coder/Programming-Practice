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