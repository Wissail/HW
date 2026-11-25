#include <iostream>
#include <math.h>

using namespace std;

int w1() {
	cout << "Введите целое число: ";
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "Число четное." << endl;
	} else {
		cout << "Число нечетное." << endl;
	}
	return 0;
}

int w2() {
	int a, b, c;
	cout << "Введите три целых числа: ";
	cin >> a >> b >> c;
	
	if (a > b && a > c) {
		cout << "Наибольшее число: " << a << endl;
	} else if (b > a && b > c) {
		cout << "Наибольшее число: " << b << endl;
	} else {
		cout << "Наибольшее число: " << c << endl;
	}
	return 0;
}

int w3() {
	int n;
	cout << "Введите любое целое число: "; cin >> n;
	if (n > 0) {
		cout << "Число положительное" << endl;
	}
	else if (n == 0) {
		cout << "Число ровно нулю" << endl;
	}
	else {
		cout << "Число отрицательное" << endl;
	}
	return 0;
}

int w4() {
	int n;
	cout << "Введите бал(0-100): "; cin >> n;
	if (n != 0 && n < 101) {
		if (101 > n > 89) {
			cout << "Отлично" << endl;
		}
		else if (90 > n > 74) {
			cout << "Хорошо" << endl;
		}
		else if (75 > n > 59) {
			cout << "Удолитворительно" << endl;
		}
		else {
			cout << "НеУд" << endl;
		} 
	}
	else {
		cout << "Такого бала нет" << endl;
	}
	return 0;
}

int w5() {
	int n;
	cout << "Введите год: "; cin >> n;
	if (n % 4 == 0) {
		if (n % 100 == 0 && n % 400 != 0) {
			cout << "Год " << n << " не весокосный" << endl;
		}
		else {
			cout << "Год " << n << " весокосный" << endl;
		}
	}
	return 0;
}

int w6() {
	double a = 20, b = 4, c = 5;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "Бесконечное количество корней" << endl;
			}
			else {
				cout << "Корней нет" << endl;
			}
		}
		else {
			double x = -c / b;
			cout << "Количество корней: 1" << endl;
			cout << "x = " << x << endl;
		}
	}
	else {
		double D = (b * b) - (4 * a * c);
			
		if (b > 0) {
			double x1 = (-b - sqrt(D)) / (2 * a);
			double x2 = (-b + sqrt(D)) / (2 * a);
			cout << "Количество корней: 2" << endl;
			cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
		}
		else if (D == 0) {
			double x = -b / (2 * a);
			cout << "Количество корней: 1" << endl;
			cout << "x = " << x << endl;
		} 
		else {
			cout << "Корней нет" << endl;
		}
	}
	return 0;
}

int w7() {
	int a, b, c;
	cout << "Введите 3 стороны треугольника: "; cin >> a >> b >> c;
	if ((a + b > c) || (b + c > a) || (c + a > b)) {
		cout << "Такого треугольника не существует" << endl;
	}
	else {
		if (a == b && b == c) {
			cout << "Равностороний треугольник" << endl;
		}
		else if (a == b || b == c || c == a) {
			cout << "Ровнобедреный треугольник" << endl;
		}
		else {
			cout << "Разностороний треугольник" << endl;
		}
	}
	return 0;
}

int w8() {
	int a, b; char c;
	cout << "Введите 2 числа: "; cin >> a >> b;
	cout << "Введите арефметическое действие(+,-,*,/): "; cin >> c;
	
	if (c == '+') {
		cout << a << " + " << b << " = " << a + b << endl;
	}
	else if (c == '-') {
		cout << a << " - " << b << " = " << a - b << endl;
	} 
	else if (c == '*') {
		cout << a << " * " << b << " = " << a * b << endl;
	}
	else if (c == '/') {
		cout << a << " / " << b << " = " << a / b << endl;
	}
	else {
		cout << "Ошибка ввода" << endl;
	}
}

int w9() {
	int a;
	cout << "Введите сумму покупки: "; cin >> a;
	if (a < 1000) {
		cout << "Ваша скидка 0%" << endl;
	}
	else if (1000 <= a && a < 5000) {
		cout << "Ваша скидка 5%" << endl;
	}
	else if (5000 <= a && a < 10000) {
		cout << "Ваша скидка 10%" << endl;
	}
	else if (10000 <= a) {
		cout << "Ваша скидка 15%" << endl;
	}
}

int w10() {
	int a;
	cout << "Введите время(0-23)"; cin >> a;
	if (6 <= a && a <= 11) {
		cout << "Доброе утро" << endl;
	} 
	else if (12 <= a && a <= 17) {
		cout << "Добрый день" << endl;
	}
	else if (23 == a && 0 <= a && a <= 5) {
		cout << "Добрый вечер" << endl;
	}
	else {
		cout << "Такого времени нет" << endl;
	}
}


int main()	{
	setlocale(LC_ALL, "ru");
	int w;
	cout << "Выберите задание (1-10): ";
	cin >> w;
	switch (w) {
	case 1: w1(); break;
	case 2: w2(); break;
	case 3: w3(); break;
	case 4: w4(); break;
	case 5: w5(); break;
	case 6: w6(); break;
	case 7: w7(); break;
	case 8: w8(); break;
	case 9: w9(); break;
	case 10: w10(); break;
	default: cout << "Нет такого задания";
}