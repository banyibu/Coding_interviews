#include <iostream>
using namespace std;

struct ListNode2 {
	char data;
	ListNode2 *ch_left, *ch_right, *father;
};

using BinaryTreeNode = ListNode2;
BinaryTreeNode* ConstructCore(char* prebeg, char* preend, char* inbeg, char* inend);//核心递归构造函数
BinaryTreeNode* reConstructBinaryTree(char* preorder, char* inorder, int length) {//重构函数
	if (preorder == nullptr || inorder == nullptr || length < 1) {
		return nullptr;
	}
	else {
		return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
	}
}
BinaryTreeNode* ConstructCore(char* prebeg, char* preend, char* inbeg, char* inend) {
	BinaryTreeNode* root = new BinaryTreeNode();
	root->data = *prebeg;
	root->ch_left = root->ch_right = root->father= nullptr;
	if (prebeg == preend) {
		if (inbeg = inend)
			return root;
		else {
			cout << "非法输入1" << endl;
			return nullptr;
		}
		//throw std::exception("invalid input.");
	}
	int tag = 0;
	char *temp = inbeg;
	while (*prebeg != *temp && temp <= inend) {
		++temp;
		++tag;
		cout << "tag:" << tag << endl;
	}
	if (*prebeg != *temp) {
		cout << "非法输入2" << endl;
		return nullptr;
	}
	//throw exception("invalid input.");
	if (tag>0) {
		root->ch_left = ConstructCore(prebeg + 1, prebeg + tag, inbeg, inbeg + tag - 1);
		cout << "构造左子树" << root->data;
		root->ch_left->father = root;
	}
	if (prebeg + tag != preend) {
		root->ch_right = ConstructCore(prebeg + tag + 1, preend, inbeg + tag + 1, inend);
		cout << "构造右子树" << root->data;
		root->ch_right->father = root;
	}
	return root;
}

ListNode2* findNextNode(ListNode2 * pNode) {
	if (pNode == nullptr) {
		return nullptr;
	}
	if (pNode->ch_right != nullptr) {
		ListNode2 *pRL = pNode->ch_right;
		while (pRL->ch_left != nullptr) {
			pRL = pRL->ch_left;
		}
		return pRL;
	}
	while(pNode->father!=nullptr&&pNode->father->ch_left != pNode ) {
		pNode = pNode->father;
	}
	if (pNode->father == nullptr)
		return nullptr;
	else
		return pNode->father;
}

//int main() {
//	char a[] = { 'a','b','d','e','h','i','c','f','g' }, b[] = { 'd','b','h','e','i','a','f','c','g' };
//	ListNode2* root = reConstructBinaryTree(a, b, 9);
//	cout << endl;
//	cout <<"d的下一个节点："<< findNextNode(root->ch_left->ch_left)->data << endl;
//	cout << "e的下一个节点：" << findNextNode(root->ch_left->ch_right)->data << endl;
//	cout << "i的下一个节点：" << findNextNode(root->ch_left->ch_right->ch_right)->data << endl;
//	if (findNextNode(root->ch_right->ch_right) == nullptr)
//		cout << "g不存在下一个节点" << endl;
//	else
//		cout << "g的下一个节点：" << findNextNode(root->ch_right->ch_right)->data << endl;
//	system("pause");
//	return 0;
//}