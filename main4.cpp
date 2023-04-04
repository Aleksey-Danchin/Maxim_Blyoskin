#include <iostream>
#include <fstream>

#define N1 6
#define N2 10
#define ONE_I(i) i + 1

using namespace std;

int a[N1];
int b[N2];

int a_index;
int b_index;

int get_index (int* array, int n) {
	for (int i = 0; i < n; i++) {
		if (array[i] > 0) {
			return i;
		}
	}

	return -1;
}

int main () {
    ifstream input_file("file1.txt");
    ofstream output_file("file2.txt");

    for (int i = 0; i < N1; i++) {
        input_file >> a[i];
    }

	a_index = get_index(a, N1);
	cout << a_index << endl;

	if (a_index == -1) {
		cout << "В массиве нет положительных чисел." << endl;
        output_file << "В массиве нет положительных чисел." << endl;
	} else {
		cout << "Количество элементов в первой часть массива " << a_index << "." << endl;
        output_file << "Количество элементов в первой часть массива " << a_index << "." << endl;
        
		cout << "Количество элементов во второй часть массива " << N1 - a_index - 1 << "." << endl;
        output_file << "Количество элементов во второй часть массива " << N1 - a_index - 1 << "." << endl;
	}

    for (int i = 0; i < N2; i++) {
        input_file >> b[i];
    }

	b_index = get_index(b, N2);
	cout << b_index << endl;

	if (b_index == -1) {
		cout << "В массиве нет положительных чисел." << endl;
        output_file << "В массиве нет положительных чисел." << endl;
	} else {
		cout << "Количество элементов в первой часть массива " << b_index << "." << endl;
        output_file << "Количество элементов в первой часть массива " << b_index << "." << endl;

		cout << "Количество элементов во второй часть массива " << N2 - b_index - 1 << "." << endl;
        output_file << "Количество элементов во второй часть массива " << N2 - b_index - 1 << "." << endl;
	}
}