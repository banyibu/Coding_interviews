//#include<iostream>
//using namespace std;
#include<stack>
#include "2.3.3list.cpp"
//����6����Ŀ�������ӡһ��������
//��ʹ��ջ�ṹ��ӡ����
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
//��ʹ�õݹ鷽ʽ��ӡ����
void printLsitreversingly_1(ListNode<int> *pHead) {
	if (pHead == nullptr)
		return;
	if (pHead->Next != nullptr)
		printLsitreversingly_1(pHead->Next);
	cout << pHead->data << endl;
}
//�򵥵�����������
void listconstruct(ListNode<int> *pHead,int number) {
	ListNode<int> *tail = pHead;
	tail->data = 0;
	for (int i = 1; i <=number; ++i) {
		ListNode<int> *tp = new ListNode<int>();
		if (tp == nullptr){
			cout << "�����ڴ�ʧ��" << endl;
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
//	cout << "ֻ��һ��Ԫ�أ�"<<endl;
//	printListrevesingly(head);
//	printLsitreversingly_1(head);
//	ListNode<int> *p = nullptr;
//	cout << "�����ָ�룺" << endl;
//	printListrevesingly(p);
//	printLsitreversingly_1(p);
//
//	listconstruct(head, 10);
//	cout << "�������ж��Ԫ��" << endl;
//	printLsitreversingly_1(head);
//	cout << "ʹ��ջ�������" << endl;
//	printListrevesingly(head);
//	system("pause");
//	return 0;
//}