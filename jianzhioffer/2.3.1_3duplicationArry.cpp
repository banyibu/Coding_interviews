#include <iostream>
using namespace std;
//题目1：一个大小为n的数字，所有数字都在0~n-1之间，找出任意重复的元素。
//从头遍历，若元素与下标值不相等，且大小与该元素值相等的下标所指位置的值与下标值也不相等，
//则交换该元素到和元素值相等的小标所在空间。
//空间复杂度O(1)，时间复杂度O(n)
bool duplicate1(int numbers[], int length,int* duplication) {
	if (numbers == nullptr || length < 0) {
		cout << "输入数组不存在\\数组长度为零" << endl;
		return false;
	}
	for (int i = 0; i != length; ++i) {
		if (numbers[i]<0 && numbers[i]>length - 1) {
			cout << "数组中元素超出界限" << endl;
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
	cout << "遍历数组无重复元素" << endl;
	return false;
}
//题目2：①不改变数组找出一个重复元素
//长度为n，元素范围1~n。
//空间复杂度O(n),时间复杂度O(n)
bool duplicate2(int* a,int length,int *b) {
	if (a == nullptr || length < 0) {
		cout << "输入数组为空或数组长度小于零" << endl;
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
//题目2：②
//空间复杂度O(1),时间复杂度O(nlog(n))
int countrange(int *a, int length, int low, int hight);
int duplicate3(int *a, int length) {
	if (a == nullptr || length <= 0) {
		cout << "输入的数组为空或长度小于1" << endl;
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
//题目2：②
//空间复杂度O(1),时间复杂度O(nlog(n))
//int countrange(const int* numbers, int length, int start, int end);
//int duplicate3(const int* numbers, int length) {
//	if (numbers == nullptr || length <= 0) {
//		cout << "数组为空或数组长度小于1" << endl;
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