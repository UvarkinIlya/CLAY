//Вычисление скалярное произведение двух векторов
#include <iostream>
#include <ctime>
#include <fstream>
#include "Func.h"

using namespace std;

void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout.precision(3);
	double** A;
	double** A1;
	double* X;
	double* B;
	double* B1;
	int size;
	int flagIn;
	cout << "1. Ввести данные в ручную" << endl;
	cout << "2. Загрузить из файла" << endl;
	cin >> flagIn;

	if (flagIn == 1) {
		cout << "Введите размер матрицы:" << endl;
		cin >> size;

		cout << "Введите матрицу:" << endl;
		A = creat_matr(size, size);
		cout << "Введите вектор B:" << endl;
		B = creat_arr(size);
	} else {
		Matr matr = input_file();
		A = matr.A;
		B = matr.B;
		size = matr.size;
	}

	X = creat_arr(size, true);
	cout << "Исходная матрица:" << endl;
	output_matr(A, size, size);
	cout << "Исходная вектор B:" << endl;
	output_arr(B, size);
	A1 = copyMatr(A, size);
	B1 = copyArr(B, size);
	cout << "Матрица после преобразований:" << endl;
	solition_slay(A, X, B, size);
	cout << "Решение:\n";
	output_arrX(X, size);

	double z = pog(A, X, B, size);
	cout << "Погрешность:\n" << z;

	out_file(A1, B1, X, size);
}