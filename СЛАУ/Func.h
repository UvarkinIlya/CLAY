#pragma once
struct Matr {
	double** A;
	double* B;
	int size;
};

double* random_arr(double* arr, int size);
double* creat_arr(int size, bool flag = false);
double** creat_matr(int size_1, int size_2, bool empty = false);
void output_matr(double** matr, int size_1, int size_2);
void output_arrX(double* arr, int size);
void output_arr(double* arr, int size);
double pog(double** A, double* X, double* B, int size);
void solition_slay(double** A, double* x, double* B, int size);
void out_file(double** A, double* B, double* X, int size);
Matr input_file();
double** copyMatr(double** A, int size);
double* copyArr(double* A, int size);