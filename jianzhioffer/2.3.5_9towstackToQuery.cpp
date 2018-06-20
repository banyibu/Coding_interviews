#include<iostream>
#include<stack>
using namespace std;
//用两个栈实现队列的功能
template <typename T>
class SQuene {
public:
	SQuene(){}
	~SQuene(){}
	void appendTail(const T node);
	T deleteHead();
private:
	stack<T> stk1;
	stack<T> stk2;
};
template<typename T>
void SQuene<T>::appendTail(const T node) {
	stk1.push(node);
	cout << "push " << node << endl;
}
template <typename T>
T SQuene<T>::deleteHead() {
	T temp=NULL;
	if (stk2.empty()) {
		
		while (!stk1.empty()) {
			temp = stk1.top();
			stk2.push(temp);
			stk1.pop();
		}
		if (stk2.empty()) {
			cout << "队已空" << endl;
			return NULL;
		}
	}
	temp = stk2.top();
	stk2.pop();
	return temp;
}

//int main() {
//	SQuene<char> charstk;
//	charstk.appendTail('a');
//	charstk.appendTail('b');
//	charstk.appendTail('c');
//	for (int i = 0; i < 4; ++i) {
//	cout << charstk.deleteHead() << endl;
//	}
//	system("pause");
//	return 0;
//}