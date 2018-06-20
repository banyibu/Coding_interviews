#include<iostream>
using namespace std;
//面试题11：题目旋转数组的最小数字
//①递归求解，考虑了旋转次数为零的情况
int MinOrder(int a[], int length);
int min(int a[], int length) {
	if (a == nullptr || length <= 0) {
		cout << "数组为空或数组长度为零" << endl;
		return NULL;
	}
	int low = 0, height = length - 1;
	if (low != height && (low+1)!=height) {
		int mid = (low + height) / 2;
		if (a[mid] >= a[height]) {
			if (a[mid] == a[low] && a[mid] == a[height]) {
				return MinOrder(a, length); //一个数组中有超过两个值相等时
			}
			low = mid;
			return min(a + low, height - low+1);
		}
		else{
			height = mid;
			return min(a, height+1);
		}
	}
	return a[low] <= a[height] ? a[low] : a[height];//为了解决数组旋转次数为零的情况
}
//②循环求解：
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
				return MinOrder(numbers + index1, index2 - index1 + 1);//一个数组中有超过两个值相等时
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
//	cout <<"一般旋转数组："<< "min_1："<<min_1(c, 5)<<"\tmin："<<min(c,5) << endl;
//	cout << "特殊旋转数组：" << min_1(b, 5) << endl;
//	system("pause");
//	return 0;
//}