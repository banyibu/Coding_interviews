#include<iostream>
using namespace std;
//����14����Ŀ�������ӣ�������Ϊn�����Ӽ���m�Σ�ʹ�ø��γ���֮���������n>1,m>1
//���ö�̬�滮���Զ����·������⣬�Ե�����������⡣
//�ٶ�̬�滮����
int maxProductAfterCutting_solution1(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; ++i) {
		max = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}
		products[i] = max;
	}
	max = products[length];
	delete[] products;
	return max;
}
//�ڶ�̬�滮����
int maxProductAfterCutting_solutiona2(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int timesOf3 = length / 3;
	if (length % 3 == 1)
		--timesOf3;
	int timesOf2 = (length - timesOf3 * 3) / 2;
	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}

//int main() {
//	for (int i = 0; i < 20; ++i) {
//		cout << maxProductAfterCutting_solution1(i) << endl;
//		cout << maxProductAfterCutting_solutiona2(i) << endl;
//	}
//	system("pause");
//	return 0;
//}