#include<iostream>
using namespace std;
//����7����Ŀ������ǰ�������������������ظ�Ԫ�أ��ع���������
struct BinaryTreeNode {
	int data;
	BinaryTreeNode* ch_left, *ch_right;
};

BinaryTreeNode* ConstructCore(int* prebeg, int* preend, int* inbeg, int* inend);//���ĵݹ鹹�캯��
BinaryTreeNode* reConstructBinaryTree(int* preorder, int* inorder, int length) {//�ع�����
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
				cout << "�Ƿ�����1" << endl;
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
		cout << "�Ƿ�����2" << endl;
		return nullptr;
		}
			//throw exception("invalid input.");
		if(tag>0){
			root->ch_left = ConstructCore(prebeg+1, prebeg + tag, inbeg, inbeg + tag - 1);
			cout << "����������" << root->data;
		}
		if (prebeg+tag != preend) {
			root->ch_right = ConstructCore(prebeg + tag+1, preend, inbeg + tag+1, inend);
			cout << "����������" << root->data;
		}
		return root;
	}
//int main() {
//	//int a[] = { 1,2,4,7,3,5,6,8 }, b[] = { 4,7,2,1,5,3,8,6 };
//	int a[] = { 1,2,3 }, b[] = { 2,1,3 };
//	int c[] = { 1,2,3 }, d[] = { 3,2,1 };
//	int e[] = { 1,2,3 }, f[] = { 1,3,0 };
//	BinaryTreeNode *root = reConstructBinaryTree(e, f, 3);
//	//cout << "���ڵ�"<<root->data <<"���ӣ�"<< root->ch_left->data << "�Һ��ӣ�"<<root->ch_right->data << endl;
//	system("pause");
//	return 0;
//}