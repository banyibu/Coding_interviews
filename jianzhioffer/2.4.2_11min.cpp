#include<iostream>
using namespace std;
//������11����Ŀ��ת�������С����
//�ٵݹ���⣬��������ת����Ϊ������
int MinOrder(int a[], int length);
int min(int a[], int length) {
	if (a == nullptr || length <= 0) {
		cout << "����Ϊ�ջ����鳤��Ϊ��" << endl;
		return NULL;
	}
	int low = 0, height = length - 1;
	if (low != height && (low+1)!=height) {
		int mid = (low + height) / 2;
		if (a[mid] >= a[height]) {
			if (a[mid] == a[low] && a[mid] == a[height]) {
				return MinOrder(a, length); //һ���������г�������ֵ���ʱ
			}
			low = mid;
			return min(a + low, height - low+1);
		}
		else{
			height = mid;
			return min(a, height+1);
		}
	}
	return a[low] <= a[height] ? a[low] : a[height];//Ϊ�˽��������ת����Ϊ������
}
//��ѭ����⣺
int min_1(int * numbers, int length) {
	if (numbers == nullptr || length <= 0)
		throw new exception("Invalid parameters!");
	int index1 = 0, index2 = length - 1, indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index2]) {
			if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
				return MinOrder(numbers + index1, index2 - index1 + 1);//һ���������г�������ֵ���ʱ
			index1 = indexMid;
		}
			
		else
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinOrder(int a[], int length) {
	if (a == nullptr || length <= 0)
		return NULL;
	int min = a[0];
	for (int i = 1; i < length; ++i) {
		if (min > a[i])
			min = a[i];
	}
	return min;
}
//int main() {
//	int a[] = { 3,4,5,1,2 }, b[] = { 1,2,3,4,5 }, c[] = { 1,0,1,1,1 };
//	cout <<"һ����ת���飺"<< "min_1��"<<min_1(c, 5)<<"\tmin��"<<min(c,5) << endl;
//	cout << "������ת���飺" << min_1(b, 5) << endl;
//	system("pause");
//	return 0;
//}