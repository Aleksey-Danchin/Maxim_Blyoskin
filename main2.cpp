#include <iostream>
// #include <windows.h>

#define N 3
#define SUM_I(i) i + 1
#define SUM_J(j) j + 1

using namespace std;

int matrix[N][N];

void enter_matrix () {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// cout << "numbers[" << SUM_I(i) << "][" << SUM_J(j) << "] = ";
			cout << "numbers[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
	
	cout << endl;
}

void print_matrix () {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << ' ';
		}
		
		cout << endl;
	}
}

int count (int row) {
	int counter = 0;

	for (int x = N - 1; x >= N - (row + 1); x--) {
		if (matrix[row][x] > 0) {
			counter++;
		}
	}

	return counter;
}

int main () {
	// SetConsoleOutputCP(CP_UTF8);
	enter_matrix ();
	print_matrix ();

	for (int y = 0; y < N; y++) {
		cout << endl << "Количество положительных элементов в строчке " << y << " = " << count(y) << endl;
	}
}