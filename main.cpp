#include <iostream>

#define N1 6
#define N2 10
#define ONE_I(i) i + 1

using namespace std;

int a[N1];
int b[N2];

int a_index;
int b_index;

void fill (int* array, int n) {
	for (int i = 0; i < n; i++) {
		cout << "[" << i << "] = ";
		cin >> array[i];
	}
}

int get_index (int* array, int n) {
	for (int i = 0; i < n; i++) {
		if (array[i] > 0) {
			return i;
		}
	}

	return -1;
}

void process (int* array, int n) {
	fill(array, n);
	int index = get_index(array, n);
	cout << index << endl;

	if (index == -1) {
		cout << "В массиве нет положительных чисел." << endl;
	} else {
		cout << "Количество элементов в первой часть массива " << index << "." << endl;
		cout << "Количество элементов во второй часть массива " << n - index - 1 << "." << endl;
	}
}

int main () {
	process(a, N1);
	process(b, N2);

	// fill(a, N1);
	// a_index = get_index(a, N1);
	// cout << a_index << endl;

	// if (a_index == -1) {
	// 	cout << "В массиве нет положительных чисел." << endl;
	// } else {
	// 	cout << "Количество элементов в первой часть массива " << a_index << "." << endl;
	// 	cout << "Количество элементов во второй часть массива " << N1 - a_index - 1 << "." << endl;
	// }

	// fill(b, N2);
	// b_index = get_index(b, N2);
	// cout << b_index << endl;

	// if (b_index == -1) {
	// 	cout << "В массиве нет положительных чисел." << endl;
	// } else {
	// 	cout << "Количество элементов в первой часть массива " << b_index << "." << endl;
	// 	cout << "Количество элементов во второй часть массива " << N2 - b_index - 1 << "." << endl;
	// }
}