#include<iostream>
using namespace std;
//面试13：题目：机器人运动范围，在m*n的方格中……
//回溯算法
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visted);
int movingCount(int threshold, int rows, int cols) {
	if (threshold < 0 || rows < 1 || cols < 1)
		return 0;
	bool* visted = new bool[rows*cols];
	if (visted == nullptr)
		cout << "标识数组内存分配失败" << endl;
	memset(visted, false, rows*cols);
	for (int i = 0; i < rows*cols; ++i) {
		cout << visted[i];
		if ((i + 1) % 20 == 0)
			cout << endl;
	}
	int count = movingCountCore(threshold, rows, cols, 0, 0, visted);
	delete[] visted;
	return count;
}
bool check(int threshold, int rows, int cols, int row, int col, bool* visted);
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visted) {
	int count = 0;
	if (check(threshold, rows, cols, row, col, visted)) {
		visted[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visted) +
			movingCountCore(threshold, rows, cols, row, col - 1, visted) +
			movingCountCore(threshold, rows, cols, row + 1, col, visted) +
			movingCountCore(threshold, rows, cols + 1, row, col, visted);
	}
	return count;
}
int getDigitSum(int number);
bool check(int threshold, int rows, int cols, int row, int col, bool* visted) {
	cout <<"行列值："<< row << col << endl;
	if (row >= 0 && row < rows&&col >= 0 && col < cols && 
		(getDigitSum(row) + getDigitSum(col)) <= threshold && !visted[row*cols + col])
		return true;
	return false;
}

int getDigitSum(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

//int main() {
//	cout << movingCount(18, 20, 20) << endl;
//	system("pause");
//	return 0;
//}