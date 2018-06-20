//将一个数字字符串转化为整数
#include <iostream>
using namespace std;
auto strtoint(char * st) {
	if (st == NULL) {
		cout << "空字符串" << endl;
	}
	int sig = 1;
	if (*st == '-') {
		sig = -1;
		++st;
	}
	else if (*st == '+') {
		++st;
	}
	int number = 0;
	while (*st != 0) {
		if (*st<'0' && *st>'9') {
			cout << "输入字符串包含非法字符" << endl;
			sig = 0;
			break;
		}
		number = number * 10 + *st - '0';
		++st;
	}
	return number * sig;
}
//int main() {
//	char p[] = "1234";
//	cout<<strtoint(p);
//	system("pause");
//}