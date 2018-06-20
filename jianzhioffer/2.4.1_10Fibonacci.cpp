#include<iostream>
using namespace std;
//����10����Ŀ��쳲���������
//�ٵݹ���⣬ʱ�临�Ӷȣ�ָ������
//��Ŀ����������̨����Ҳ��fibonacci��Ӧ�����⡣
long long fibonacci_1(unsigned int n) {
	if (n < 0) {
		cout << "������������" << endl;
	}
	else if (n == 0||n==1)
		return n;
	else
		return fibonacci_1(n - 1) + fibonacci_1(n - 2);
}
//��ʹ��ѭ�������ʱ�临�Ӷ�O(n)
long long fibonacci_2(unsigned int n) {
	long long tmp[2] = { 0,1 };
	if (n < 0) {
		cout << "������������" << endl;
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