#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

double* random_arr(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}

	return arr;
}

double* creat_arr(int size, bool flag = false) {
	/*Генерация массива*/
	int const value = 5;

	double* arr;
	arr = new double[size];

	if (flag) {
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}

		return arr;
	}

	if (size > value) {
		arr = random_arr(arr, size);
	}
	else {
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}

	return arr;
}

double** creat_matr(int size_1, int size_2, bool empty = false) {
	double** matr;

	matr = new double* [size_1];
	if (empty) {
		for (int i = 0; i < size_1; i++) {
			matr[i] = new double[size_2];
		}
		return matr;
	}
	for (int i = 0; i < size_1; i++) {
		matr[i] = creat_arr(size_2);
	}

	return matr;
}

void output_matr(double** matr, int size_1, int size_2) {
	cout.precision(5);
	for (int i = 0; i < size_1; i++) {
		for (int j = 0; j < size_2; j++) {
			cout.width(10);
			cout << matr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void output_arrX(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		//cout.width(5);
		cout << 'x' << i + 1 << " = " << arr[i] << endl;
	}

	cout << endl;
}

void output_arr(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		//cout.width(5);
		cout << arr[i] << " ";
	}

	cout << endl;
}

double pog(double** A, double* X, double* B, int size) {
	double temp_sum = 0;
	double pogreh = 0;
	double tepm_pog = 0;

	for (int i = 0; i < size; i++) {

		temp_sum = 0;
		for (int j = 0; j < size; j++) {
			temp_sum += A[i][j] * X[j];
		}

		tepm_pog = abs(temp_sum - B[i]);
		if (tepm_pog > pogreh) {
			pogreh = tepm_pog;
		}
	}

	return pogreh;
}

void out_file(double** A, double* B, double* X, int size) {
	ofstream file;
	file.open("matr.txt");
	cout.precision(3);

	file << size << endl;

	//Вывод матрицы
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file << A[i][j] << " ";
		}
		file << endl;
	}

	for (int i = 0; i < size; i++) {
		file << B[i] << ' ';
	}

	file << endl << "Решение:" << endl;
	for (int i = 0; i < size; i++) {
		file << 'x' << i + 1 << " = " << X[i] << endl;
	}

	double z = pog(A, X, B, size);
	file << endl << "Погрешность:" << endl << z;

	file.close();
}

struct Matr {
	double** A;
	double* B;
	int size;
};

Matr input_file() {
	double** A;
	double* B;
	double* X;
	Matr matr;

	ifstream file;
	file.open("matr.txt");
	int size;
	file >> size;

	A = creat_matr(size, size, true);
	B = creat_arr(size, true);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file >> A[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		file >> B[i];
	}

	file.close();

	matr.A = A;
	matr.B = B;
	matr.size = size;

	return matr;
}

double** copyMatr(double** A, int size) {
	double** outMatr = new double* [size];

	for (int i = 0; i < size; i++) {
		outMatr[i] = new double[size];
		for (int j = 0; j < size; j++) {
			outMatr[i][j] = A[i][j];
		}
	}

	return outMatr;
}

double* copyArr(double* A, int size) {
	double* outArr = new double[size];

	for (int j = 0; j < size; j++) {
		outArr[j] = A[j];
	}

	return outArr;
}

void solition_slay(double** A, double* x, double* B, int size) {
	double p;
	double sum = 0;

	for (int j = 0; j < size; j++) {
		for (int i = j + 1; i < size; i++) {
			p = A[i][j] / A[j][j];

			for (int k = j; k < size; k++) {
				A[i][k] -= p * A[j][k];
			}

			B[i] -= p * B[j];
		}
	}

	for (int i = size - 1; i >= 0; i--) {
		sum = 0;
		for (int j = i + 1; j < size; j++) {
			sum += x[j] * A[i][j];
		}

		x[i] = (B[i] - sum) / A[i][i];
	}

	output_matr(A, size, size);
}