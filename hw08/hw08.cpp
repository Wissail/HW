#include <iostream>

using namespace std;

int w1() {
	int num;
	cout << "Введите любое число: ";
	cin >> num;
	for (; num > 0; num /= 10) {
		cout << num % 10;
	}
	return 0;
}

void w2() {
	int num, sum = 0;
	cout << "Введите любое число: ";
	cin >> num;
	for (; num > 0; num /= 10) {
		sum += num % 10;
	}
	cout << "Сумма всех чисел = " << sum;
}

void w3() {
	int days, sum = 0;
	cout << "Ведите количество дней: ";
	cin >> days;
	for (int i = 15; days != 0; --days, i += 2) {
		sum += i;
	}
	cout << "Улитка проболзла " << sum << "см";
}

void w4() {
	int bin, sum = 0;
	cout << "Введите 9 раз 1 или 0\n";
	for (int i = 0; i < 9; i++) {
		cin >> bin;
		sum += bin;
	}
	if (sum % 2 == 0) {
		cout << "Положительно";
	}
	else {
		cout << "Отрицательно";
	}
}

void w5() {
	int month = 0, week = 0, day = 1, dayMonth = 0, sumHDays = 0;
	cout << "Введите месяц(1-12):";
	cin >> month;
	cout << "Введите день недели(1-7):";
	cin >> week;
	switch (month) {
	case 1:  cout << "\nЯнварь", dayMonth = 31; break;
	case 2:  cout << "\nФевраль", dayMonth = 28; break;
	case 3:  cout << "\nМарт", dayMonth = 31; break;
	case 4:  cout << "\nАпрель", dayMonth = 30; break;
	case 5:  cout << "\nМай", dayMonth = 31; break;
	case 6:  cout << "\nИюнь", dayMonth = 30; break;
	case 7:  cout << "\nИюль", dayMonth = 31; break;
	case 8:  cout << "\nАвгуст", dayMonth = 31; break;
	case 9:  cout << "\nСеньтябрь", dayMonth = 30; break;
	case 10: cout << "\nОктябрь", dayMonth = 31; break;
	case 11: cout << "\nНоябрь", dayMonth = 30; break;
	case 12: cout << "\nДекабрь", dayMonth = 31; break;
	default:
		cout << "\nНет такого месяца";
		return;
	}
	cout << "\nПн  Вт  Ср  Чт  Пт  Сб  Вс\n";
	for (int i = 1; i < week; i++) {
		cout << "    ";
	}
	for (int i = week; day <= dayMonth; i++) {
		if (day < 10) {
			cout << day << "   ";
		}
		else {
			cout << day << "  ";
		}
		if (i % 7 == 0) {
			cout << "\n";
		}
		if (i % 7 == 6 || i % 7 == 0) {
			sumHDays++;
		}

		day++;
	}
	cout << "\n";
	cout << "Количество выходных " << sumHDays;
}


int main() {
	setlocale(LC_ALL, "RU");
	int w;
	cout << "Выберите задание (1-5): ";
	cin >> w;
	switch (w) {
	case 1: w1(); break;
	case 2: w2(); break;
	case 3: w3(); break;
	case 4: w4(); break;
	case 5: w5(); break;
	default: cout << "Нет такого задания";
	}
}
