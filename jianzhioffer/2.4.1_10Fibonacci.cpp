#include<iostream>
using namespace std;
//面试10：题目：斐波那契数列
//①递归求解，时间复杂度，指数级别
//题目二：青蛙跳台问题也是fibonacci的应用问题。
long long fibonacci_1(unsigned int n) {
	if (n < 0) {
		cout << "数据输入有误" << endl;
	}
	else if (n == 0||n==1)
		return n;
	else
		return fibonacci_1(n - 1) + fibonacci_1(n - 2);
}
//②使用循环解决，时间复杂度O(n)
long long fibonacci_2(unsigned int n) {
	long long tmp[2] = { 0,1 };
	if (n < 0) {
		cout << "输入数据有误" << endl;
		return NULL;
	}
	else if (n == 0||n==1)
		return tmp[n];
	for (int i = 2; i <= n; ++i) {
		int tp = tmp[1];
		tmp[1] += tmp[0];
		tmp[0] = tp;
	}
	return tmp[1];
}

//int main() {
//	for (int i = 0; i <= 40; ++i) {
//	cout << fibonacci_1(i) << "\t";
//	}
//	cout << endl;
//	for (int i = 0; i <= 40; ++i) {
//		cout << fibonacci_2(i) << "\t";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}