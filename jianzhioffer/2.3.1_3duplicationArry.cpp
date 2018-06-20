#include <iostream>
using namespace std;
//��Ŀ1��һ����СΪn�����֣��������ֶ���0~n-1֮�䣬�ҳ������ظ���Ԫ�ء�
//��ͷ��������Ԫ�����±�ֵ����ȣ��Ҵ�С���Ԫ��ֵ��ȵ��±���ָλ�õ�ֵ���±�ֵҲ����ȣ�
//�򽻻���Ԫ�ص���Ԫ��ֵ��ȵ�С�����ڿռ䡣
//�ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(n)
bool duplicate1(int numbers[], int length,int* duplication) {
	if (numbers == nullptr || length < 0) {
		cout << "�������鲻����\\���鳤��Ϊ��" << endl;
		return false;
	}
	for (int i = 0; i != length; ++i) {
		if (numbers[i]<0 && numbers[i]>length - 1) {
			cout << "������Ԫ�س�������" << endl;
			return false;
		}
	}
	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if(numbers[numbers[i]]!=numbers[i]){
				int temp = numbers[numbers[i]];
				numbers[numbers[i]] = numbers[i] ;
				numbers[i] = temp;
			}
			else {
				*duplication = numbers[i];
				return true;
			}
		}
	}
	cout << "�����������ظ�Ԫ��" << endl;
	return false;
}
//��Ŀ2���ٲ��ı������ҳ�һ���ظ�Ԫ��
//����Ϊn��Ԫ�ط�Χ1~n��
//�ռ临�Ӷ�O(n),ʱ�临�Ӷ�O(n)
bool duplicate2(int* a,int length,int *b) {
	if (a == nullptr || length < 0) {
		cout << "��������Ϊ�ջ����鳤��С����" << endl;
		return false;
	}
	int *temp = new int[length];
	for (int i = 0; i < length; ++i) {
		temp[i] = 0;
	}
	for (int i = 0; i < length; ++i) {
		if (temp[a[i]] != 0) {
			*b = a[i];
			return true;
		}
		temp[a[i]]++;
	}
	return false;
}
//��Ŀ2����
//�ռ临�Ӷ�O(1),ʱ�临�Ӷ�O(nlog(n))
int countrange(int *a, int length, int low, int hight);
int duplicate3(int *a, int length) {
	if (a == nullptr || length <= 0) {
		cout << "���������Ϊ�ջ򳤶�С��1" << endl;
		return -1;
	}
	int low = 1, hight = length - 1;
	
	while (low <hight) {
		int mid = (hight-low) / 2 +low;
		int count = countrange(a, length, mid, hight);
		cout << "count" << count << endl;
		if (count >= hight-mid+2) {
			if (mid == hight) {
				return mid;
			}
			low = mid;
			cout << "change low" <<low<< endl;
		}
		else if(count=countrange(a,length,low,mid),count>=mid-low+2){
			if (mid == low) {
				return low;
			}
			hight = mid-1;
			cout << "change hight" << hight << endl;
		}
		cout << "low:" << low << "highet:" << hight << endl;
	}
	return low;
}
int countrange(int *a, int length, int low, int hight) {
	if (length == 0) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < length; ++i) {
		if (a[i] <= hight && a[i] >= low) {
			++count;
		}
	}
	return count;
}
//��Ŀ2����
//�ռ临�Ӷ�O(1),ʱ�临�Ӷ�O(nlog(n))
//int countrange(const int* numbers, int length, int start, int end);
//int duplicate3(const int* numbers, int length) {
//	if (numbers == nullptr || length <= 0) {
//		cout << "����Ϊ�ջ����鳤��С��1" << endl;
//	}
//	int start = 1;
//	int end = length - 1;
//	while (end >= start) {
//		int mid = ((end - start) >> 1) + start;
//		int count = countrange(numbers, length, start, mid);
//		if (end == start) {
//			if (count > 1)
//				return start;
//			else
//				break;
//		}
//		if (count > (mid - start + 1))
//			end = mid;
//		else
//			start = mid + 1;
//	}
//	return -1;
//}
//int countrange(const int* numbers, int length, int start, int end) {
//	{
//		if (numbers == nullptr)
//			return 0;
//		int count = 0;
//		for (int i = 0; i < length; ++i) {
//			if (numbers[i] >= start && numbers[i] <= end)
//				++count;
//		}
//		return count;
//	} }
//int main() {
//	int a[] = { 1,2,3,4,2,3,4 }, b[] = { 1, 2, 3, 4,2},c=-1,d=-1;
//	//cout << duplicate1(a, 7, &c) << "	" << duplicate1(b, -1, &d) << endl;
//	//cout << c << d << endl;
//	//cout << endl << endl << endl << endl;
//	cout << duplicate3(b, 5) << endl;
//	//cout << c << endl;
//	system("pause");
//	return 0;
//}