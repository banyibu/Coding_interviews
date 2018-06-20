#include<iostream>
#include<random>
using namespace std;

void quicksort_m(int *numbers, int length) {
	int low = 0, height = length - 1;
	if (numbers == nullptr || length <= 0) {
		cout << "输入数组不存在或数组长度为零" << endl;
		return;
	}
	if (low == height)
		return;
	int mid = numbers[0];
	//swap(mid, numbers[height]);
	//--height;
	while (low != height) {
		if (numbers[height] > mid)
			--height;
		else{
			swap(numbers[low], numbers[height]);
			++low;
		}
	}
	//swap(numbers[length - 1], numbers[low]);
	if (low > 0) {
		quicksort_m(numbers, low);
	}
	if (length - low - 1 > 0) {
		quicksort_m(numbers + low+1, length - low-1);
	}
	return;
	
}

int Partion(int data[], int length, int start, int end) {
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");
	uniform_int_distribution<unsigned>u(start, end);
	default_random_engine e;
	int index = u(e);
	swap(data[index], data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			++small;
			if (small != index)
				swap(data[small], data[index]);
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end) {
	if (start == end)
		return;
	int index = Partion(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}
//void qsort(int *num,int mid)
//int main() {
//	int c[6] = { 2,3,1,4,3,5 };
//	quicksort_m(c, 6);
//	//QuickSort(c, 6, 0, 5);
//	for (int i = 0; i < 6; ++i) {
//		cout << c[i] << "\t";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}