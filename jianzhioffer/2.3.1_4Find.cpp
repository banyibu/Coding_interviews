#include<iostream>
using namespace std;
//��Ŀ��һ���������к��ж��Ǵ�С�����˳�����еģ�����һ�������������Ƿ��ڸþ����У�
bool Find(int *matrix, int rows, int columns, int number) {
	bool find = false;
	if (matrix != nullptr && rows > 0 && columns > 0) {
		int row = 0, column = columns - 1;
		while (row<rows && column>=0) {
			if (*(matrix + row * columns + column) == number) {
				find = true;
				break;
			}
			else if (matrix[row*columns + column] > number) {
				--column;
			}
			else {
				++row;
			}
		}
	}
	return find;
}

//int main() {
//	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	cout << Find(a[0], 3, 3, 5) << endl;
//	cout << Find(a[0], 3, 3, 10) << endl;
//	return 0;
//}