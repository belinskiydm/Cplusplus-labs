// Matrix_lesson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Шаблоный
template <class T>
class Matrixt {
	T **a;
	int n; 
	int m;
	Matrix();
	~Matrix();
	Matrix(int n1, int m1);

	//метод чтения из массива констант
	void set_const();

	//оператор присваивания. возвращается шаблон класса и передается экземпляр шаблона класса.
	Matrixt& operator=(Matrixt &);
};

template <class T>
Matrixt<T>::Matrixt(int n1, int m1) {
	n = n1;
	m = m1;
	a = new T*[n];
	for (int i = 0; i < n; i++)
		a[i] = new T[m];
}

template <class T>
void Matrixt<T>::set_const() {
	int i, k;
	for (i = 0, k = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = a[k++];
			//cin>>a[i][j];
			
}

//Рассмотрим параметризованный оператор равно

template <class T>
//возвращается ссылка на класс
Matrixt<T>& Matrixt<T>::operator=(Matrixt<T> &r) {
	if (&r != this) {
		if (n != r.n || m != r.m) {
			Matrixt<T>::~Matrixt();
			Matrix<T>::Matrixt(r.n, r.m);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j = m; j++)
				a[i][j] = r.a[i][j];
	}
}

//
template <class T>
Matrixt<T>* Matrixt<T>::operator*(Matrixt<T> &r) {
	Matrixt<T> *z;
	int i, k;
	z = new MAtrixt<T>(n, r.m);
	
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			for (k = 0, z->a[i][j]; k < m; k++)
				z->a[i][j] += a[i][k] * r.a[k][j];
	
	return z;
}


int main()
{
	int i, j, n;
	Matrixt <double> zt(1, 1);
	cin >> zt; 
	cout << zt;
	
	Matrixt <int> at(2, 2);
	Matrixt <int> *ct;
	ct = new Matrix<int>(2, 2);
	ct->set_const();
	at = *ct;
	//cout<<*ct - так нельзя
	cout << at;

	ct = at*at;
	at = *ct;
	cout << at;

	//для прямоугольных матриц умножение такое А на А транспонированная
	
	Matrixt <int> pt(2, 2);
	pt = at.transponir();

	//В шаблонных записях извлечение из потока
	//(istream &in, Matrix<T> &r);



	return 0;
}

