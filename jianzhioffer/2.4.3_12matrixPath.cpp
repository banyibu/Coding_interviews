#include<iostream>
using namespace std;
//面试题：12，题目：矩阵中求路径是否存在；
bool hasPathCore(const char *matrix, int rows, int cols, int row, int col,
	const char* str, int &pathLength, bool* visted);
bool hasPath_1(char *matrix, int rows, int cols, char* str) {
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
		return false;
	}
	bool* visted = new bool[rows*cols];
	memset(visted, 0, rows*cols);
	int pathLength = 0;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visted)) {
				return true;
			}
		}
	}
	delete[] visted;
	return false;
}

bool hasPathCore(const char *matrix, int rows, int cols, int row, int col,
	const char* str, int &pathLength, bool* visted) {
	if (str[pathLength] == '\0')
		return true;
	bool hasPath = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols
		&&matrix[row*cols + col] == str[pathLength] && !visted[row*cols + col]) {
		++pathLength;
		visted[row*cols + col] = true;
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visted);
		if (!hasPath) {
			--pathLength;
			visted[row*cols + col] = false;
		}
	}
	return hasPath;
}

//int main() {
//	char a[][4] = { {'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'} };
//	char b[] = "bfce";
//	//char* bb = b;
//	//while (*bb != '\0') {
//	//	cout << *bb << '\t';
//	//	++bb;
//	//}	
//	bool result=hasPath_1(a[0], 4, 4, b);
//	if (result)
//		cout << "包含路径" << endl;
//	else
//		cout << "不包含路径" << endl;
//	system("pause");
//	return 0;
//}