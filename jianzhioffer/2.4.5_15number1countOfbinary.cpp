#include<iostream>
using namespace std;
//����15����Ŀ�������Ķ����Ʊ�ʾ�У����е�1�ĸ���
//����ͨ������ѭ�������ͻ����б�ʾ�����Ķ�����λ���й�
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
//�ڶ����Ʊ�ʾ���������ж��ٸ�1��ѭ�����ٴ�
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
//		cout << "����" << i << "�У�1�ĸ���NumberOf1��" << endl;
//		cout<< NumberOf1(i) << endl;
//		cout <<"NumberOf1_1:" <<NumberOf1_1(i) << endl;
//	}
//	system("pause");
//	return 0;
//}