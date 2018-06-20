//#include<iostream>
//using namespace std;
#include<stack>
#include "2.3.3list.cpp"
//面试6：题目：反向打印一个单链表；
//①使用栈结构打印链表
void printListrevesingly(ListNode<int> *pHead) {
	std::stack<ListNode<int> >nodes;
	ListNode<int>* tempNode = pHead;
	while (tempNode != nullptr) {
		nodes.push(*tempNode);
		tempNode = tempNode->Next;
	}
	while (!nodes.empty()) {
		cout << nodes.top().data << endl;
		nodes.pop();
	}
}
//②使用递归方式打印链表
void printLsitreversingly_1(ListNode<int> *pHead) {
	if (pHead == nullptr)
		return;
	if (pHead->Next != nullptr)
		printLsitreversingly_1(pHead->Next);
	cout << pHead->data << endl;
}
//简单的链表构建函数
void listconstruct(ListNode<int> *pHead,int number) {
	ListNode<int> *tail = pHead;
	tail->data = 0;
	for (int i = 1; i <=number; ++i) {
		ListNode<int> *tp = new ListNode<int>();
		if (tp == nullptr){
			cout << "分配内存失败" << endl;
			break;
		}
		tp->data = i;
		tail->Next = tp;
		tail = tp;
	}
	tail->Next = nullptr;
	//return pHead;
}
//int main() {
//	ListNode<int> *head = new ListNode<int>();
//	head->Next = nullptr;
//	head->data = 11;
//	cout << "只有一个元素："<<endl;
//	printListrevesingly(head);
//	printLsitreversingly_1(head);
//	ListNode<int> *p = nullptr;
//	cout << "传入空指针：" << endl;
//	printListrevesingly(p);
//	printLsitreversingly_1(p);
//
//	listconstruct(head, 10);
//	cout << "链表中有多个元素" << endl;
//	printLsitreversingly_1(head);
//	cout << "使用栈的情况：" << endl;
//	printListrevesingly(head);
//	system("pause");
//	return 0;
//}