//�����в��ҵ�����K��Ԫ��
#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T data;
	Node * next;
	//friend Node * FindthToTail(Node*, unsigned);
	Node(T i) :data(i), next(nullptr) {}
};
template<typename T>
Node<T> * FindthToTail(Node<T> *L, unsigned k) {
	if (L == nullptr) {
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
	else if (k <= 0) {
		cout << "���ҷ�Χ�Ƿ�" << endl;
		return nullptr;
	}
	Node<T> *pr = L, *pb = L;
	int i = 0;
	while (pb != nullptr && i != k) {
		pb = pb->next;
		++i;
	}
	//cout << pb->data << endl;
	if (i < k) {
		cout << "���ҷ�Χ���������С" << endl;
		return nullptr;
	}
	//cout << i;
	while (pb != nullptr) {
		pb = pb->next;
		pr = pr->next;
		//cout << pr->data <<"	";
	}
	//cout <<"pr��"<< pr->data<<endl;
	return pr;


}
//template <typename T>
//class List{
//public:
//	List(Node<T> *ph = nullptr,rsize_t sz= 0)Phead(ph)/*,size(sz)*/{}
//	//rsize_t getsize() { return size; }
//private:
//	//size_t size;
//	Node<T> *Phead;
//};
//int main() {
//	Node<int> head(0);
//	//List->data = 0;
//	Node<int> *List = &head;
//	Node<int> *p = List;
//	List->next = nullptr;
//	for (int i = 1; i < 10; ++i) {
//		Node<int> *pt = new Node<int>(i);
//		p->next = pt;
//		p = pt;
//	}
//	for (Node<int> *pr = List; pr != nullptr; pr = pr->next) {
//		cout << pr->data;
//	}
//	cout << endl;
//	if (FindthToTail(List, 0) != nullptr) {
//		cout << (FindthToTail(List, 0))->data << endl;
//	}
//	system("pause");
//	return 0;
//
//}