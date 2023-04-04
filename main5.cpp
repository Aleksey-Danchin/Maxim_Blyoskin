#include <iostream>
#include <fstream>

#define N 3

using namespace std;

int matrix[N][N];

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
    ifstream input_file("file3.txt");
    ofstream output_file("file4.txt");

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			input_file >> matrix[i][j];
		}
	}

	print_matrix();

	for (int y = 0; y < N; y++) {
		output_file << endl << "Количество положительных элементов в строчке " << y << " = " << count(y) << endl;
	}
}