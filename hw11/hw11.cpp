#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void arr(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % 201) - 100;
	}
}

void arr(double array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % 20001) / 100.0 - 100;
	}
}

int w1() {
	const int size = 100;
	int arrW[size];
	arr(arrW, size);
	int min = arrW[0], max = arrW[0];
	for (int i = 0; i < size; i++) {
		if (max < arrW[i])
			max = arrW[i];
		if (min > arrW[i])
			min = arrW[i];
	}
	cout << "Минимальное значение массива: " << min << "\n";
	cout << "Максимальное значение массива: " << max << "\n";
	return 0;
}

int w2() {
	const int size = 100;
	int arrW[size];
	arr(arrW, size);
	int sum = arrW[0];
	for (int i = 1; i < size; i++) {
		sum += arrW[i];
	}
	cout << "Сумма масива: " << sum;
	return 0;
}

int w3() {
	int arrW[12], a = 0, b = 0;
	cout << "Введите прибыль фирмы за год(12 месяцев)\n";
	for (int i = 0; i < 12; i++) {
		cout << "Прибыль за " << i + 1 << " месяц: ";
		cin >> arrW[i];
	}
	cout << "Введите период прибыли фирмы\n";
	cout << "От: "; cin >> a;
	cout << "До: "; cin >> b;
	
	int minI = a - 1, maxI = b - 1;
	int min = arrW[minI], max = arrW[maxI];

	for (int i = a; i < b; i++) {
		if (max < arrW[i]) {
			max = arrW[i];
			maxI = i;
		}
		if (min > arrW[i]) {
			min = arrW[i];
			minI = i;
		}
	}
	cout << "Максимальная прибыль " << arrW[maxI] << " за " << maxI + 1 << " месяц" << "\n";
	cout << "Минимальная прибыль " << arrW[minI] << " за " << minI + 1 << " месяц" << "\n";
	return 0;
}

int w4() {
	int size, a = -1, b = 0, ma = 0, mb = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	double* arrW = new double[size];
	arr(arrW, size);
	double min = arrW[0], max = arrW[0], msum = 0, evenum = 1, betwsum = 1, negbetwsum = 0;
	for (int i = 0; i < size; i++) {
		if (arrW[i] < 0) msum += arrW[i];
		if (min > arrW[i]) {
			min = arrW[i];
			ma = i;
		}
		if (max < arrW[i]) {
			max = arrW[i];
			mb = i;
		}
		if (i % 2 == 0) evenum *= arrW[i];
		if (arrW[i] < 0 && a == -1) a = i;
		if (arrW[i] < 0) b = i;
	}

	for (int i = a + 1; i < b; i++) negbetwsum += arrW[i];

	int lo = ma, hi = mb;
	if (lo > hi) {
		lo = mb;
		hi = ma;
	}
	for (int i = lo + 1; i < hi; i++) {
		betwsum *= arrW[i];
	}
	
	cout << "Сумма отрицательных элементов массива: " << msum << "\n"; 
	cout << "Произведение элементов, находящихся между min и max элементами " << betwsum << "\n";
	cout << "Произвидение элементов, находящихся на четных позициях " << evenum << "\n";
	cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами " << negbetwsum << "\n";
	delete[] arrW;
	return 0;
}



int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int w;
	cout << "Выберите задание (1-4): ";
	cin >> w;
	switch (w) {
	case 1: w1(); break;
	case 2: w2(); break;
	case 3: w3(); break;
	case 4: w4(); break;
	default: cout << "Нет такого задания";
	}
}
