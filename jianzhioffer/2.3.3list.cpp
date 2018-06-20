#include<iostream>
using namespace std;
//链表节点定义
template <typename T>
struct ListNode {
	T data;
	ListNode* Next;
};
//链表中插入一个值
template <typename T>
void AddTotail(ListNode<T>** pHead, T value) {
	ListNode<T>* pNew = new ListNode<T>();
	pNew->data = value;
	pNew->Next = nullptr;
	if (*pHead == nullptr) {
		*pHead = pNew;
	}
	else {
		ListNode<T>* temp = *pHead;
		while (temp->Next != nullptr) {
			temp = temp->Next;
		}
		temp->Next = pNew;
	}
}
//在链表中删除一个值
template <typename T>
void RemoveNode(ListNode<T>** pHead, T value) {
	if (pHead == nullptr && *pHead == nullptr)
		return;
	ListNode<T> deNode=nullptr;
	if ((*pHead)->data == value) {
		deNode = *pHead;
		*pHead = (*pHead)->Next;
	}
	else {
		ListNode<T> tempNode = *pHead;
		while (tempNode->Next != nullptr && tempNode->Next->data != value)
			tempNode = tempNode->Next;
		if (tempNode->Next != nullptr && tempNode->Next->data == value) {
			deNode = tempNode->Next;
			tempNode->Next = tempNode->Next->Next;
		}
	}
	delete deNode;
}