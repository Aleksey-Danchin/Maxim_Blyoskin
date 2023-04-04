#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    const int row = 3, column = 2;
    int array[row][column];

    //создаем объект класса ifstream
    //и сразу указываем файл, с которого будем читать
    ifstream f("input.txt");

    //читаем файл и прочитанное запоминаем в массив
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            f >> array[i][j];
            cout << array[i][j] << " ";
        }

        cout << endl;
    }

    //создаем объект класса ofstream
    ofstream output_file("output.txt");

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            output_file << array[i][j] << " ";
        }

        output_file << endl;
    }

    return 0;
}