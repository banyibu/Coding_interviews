#include<iostream>
using namespace std;
//面试7：题目：给出前序遍历和中序遍历，无重复元素，重构二叉树；
struct BinaryTreeNode {
	int data;
	BinaryTreeNode* ch_left, *ch_right;
};

BinaryTreeNode* ConstructCore(int* prebeg, int* preend, int* inbeg, int* inend);//核心递归构造函数
BinaryTreeNode* reConstructBinaryTree(int* preorder, int* inorder, int length) {//重构函数
	if (preorder == nullptr || inorder == nullptr || length < 1) {
		return nullptr;
	}
	else {
		return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
	}
}
BinaryTreeNode* ConstructCore(int* prebeg, int* preend, int* inbeg, int* inend) {
		BinaryTreeNode* root = new BinaryTreeNode();
		root->data = *prebeg;
		root->ch_left = root->ch_right = nullptr;
		if (prebeg == preend) {
			if (inbeg = inend)
				return root;
			else{
				cout << "非法输入1" << endl;
				return nullptr;
			}
				//throw std::exception("invalid input.");
		}
		int tag = 0;
		int *temp = inbeg;
		while (*prebeg != *temp && temp <= inend) {
			++temp;
			++tag;
			cout <<"tag:"<<tag << endl;
		}
		if (*prebeg != *temp){
		cout << "非法输入2" << endl;
		return nullptr;
		}
			//throw exception("invalid input.");
		if(tag>0){
			root->ch_left = ConstructCore(prebeg+1, prebeg + tag, inbeg, inbeg + tag - 1);
			cout << "构造左子树" << root->data;
		}
		if (prebeg+tag != preend) {
			root->ch_right = ConstructCore(prebeg + tag+1, preend, inbeg + tag+1, inend);
			cout << "构造右子树" << root->data;
		}
		return root;
	}
//int main() {
//	//int a[] = { 1,2,4,7,3,5,6,8 }, b[] = { 4,7,2,1,5,3,8,6 };
//	int a[] = { 1,2,3 }, b[] = { 2,1,3 };
//	int c[] = { 1,2,3 }, d[] = { 3,2,1 };
//	int e[] = { 1,2,3 }, f[] = { 1,3,0 };
//	BinaryTreeNode *root = reConstructBinaryTree(e, f, 3);
//	//cout << "根节点"<<root->data <<"左孩子："<< root->ch_left->data << "右孩子："<<root->ch_right->data << endl;
//	system("pause");
//	return 0;
//}