#include<iostream>
using namespace std;
//面试15：题目：整数的二进制表示中，含有的1的个数
//①普通做法，循环次数和机器中表示整数的二进制位数有关
int NumberOf1(int n) {
	int count = 0;
	int num = 1;
	while (num) {
		if (num & n)
			++count;
		num=num<< 1;
		//cout << num << endl;
	}
	return count;
}
//②二进制表示的整数中有多少个1，循环多少次
int NumberOf1_1(int n) {
	int count = 0;
	while (n) {
		++count;
		n = (n - 1)&n;
	}
	return count;
}

//int main() {
//	for (int i = -10; i < 10; ++i) {
//		//cout << "ceshi:" << endl;
//		cout << "数字" << i << "中，1的个数NumberOf1：" << endl;
//		cout<< NumberOf1(i) << endl;
//		cout <<"NumberOf1_1:" <<NumberOf1_1(i) << endl;
//	}
//	system("pause");
//	return 0;
//}