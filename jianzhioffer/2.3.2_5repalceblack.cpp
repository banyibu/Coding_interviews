#include <iostream>
using namespace std;
//������5����Ŀ������һ�����пո���ַ����������еĿո�ԭ���滻Ϊ��%20����
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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
		cout << "�ַ����ռ䲻��" << endl;
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