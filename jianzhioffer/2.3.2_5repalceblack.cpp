#include <iostream>
using namespace std;
//面试题5，题目：给定一个含有空格的字符串，将其中的空格原地替换为“%20”。
//时间复杂度O(n),空间复杂度O(1)
void replace_balck(char *str, int length) {
	if (str == nullptr || length <= 0) {
		return;
	}
	int count = 0, Olength=0;
	char * tmp_str = str;
	while (*tmp_str != 0) {
		if (*tmp_str == ' ')
			++count;
		++tmp_str;
		++Olength;
	}
	cout << count << endl;
	int leng = Olength + count*2;
	if (leng + 1 > length) {
		cout << "字符串空间不足" << endl;
		return;
	}
		
	for (int i = leng-1,j=Olength-1; i>=0 && j>=0 ; --i,--j) {
		if (str[j] == ' ') {
			str[i] = '0';
			str[i - 1] = '2';
			str[i - 2] = '%';
			i -= 2;
		}
		else {
			str[i] = str[j];
		}
	}
}
//int main() {
//	char a[26] = "hello  word haha ";
//	replace_balck(a, 26);
//	int i = 0;
//	while (a[i]!= 0) {
//		cout << a[i];
//		++i;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//	
//}