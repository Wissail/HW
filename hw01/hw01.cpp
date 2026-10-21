#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void task1() {
	int seconds, minutes, hours;

	cout << "Введите время в секундах: ";
	cin >> seconds;

	if (seconds < 0) {
		cout << "Время не может быть отрицательным";
		return;
	}

	hours = seconds / 3600;
	minutes = seconds % 3600 / 60;
	seconds = seconds % 60;

	cout << hours << " ч " << minutes << " мин " << seconds << " сек";
}

void task2() {
	double number;
	int dollars, cents;

	cout << "Введите сумму: ";
	cin >> number;

	if (number < 0) {
		cout << "Сумма не может быть отрицательной";
		return;
	}

	int total = round(number * 100);
	dollars = total / 100;
	cents = total % 100;

	cout << dollars << " долларов и " << cents << " центов";
}

void task3() {
	int days, weeks;

	cout << "Введите количество дней: ";
	cin >> days;

	if (days < 0) {
		cout << "Количество дней не может быть отрицательным";
		return;
	}

	weeks = days / 7;
	days = days % 7;

	cout << weeks << " недель и " << days << " дней";
}

void task4() {
	double distance, time, speed;
	int minutes, seconds, totalSeconds;

	cout << "Вычисление скорости бега\n";
	cout << "Введите длину дистанции (метров) = ";
	cin >> distance;
	cout << "Введите время (мин.сек) = ";
	cin >> time;

	minutes = time;
	seconds = round((time - minutes) * 100);

	if (distance <= 0 || time <= 0 || seconds >= 60) {
		cout << "Некорректные данные";
		return;
	}

	totalSeconds = minutes * 60 + seconds;
	speed = distance / totalSeconds * 3.6;

	cout << "Дистанция: " << distance << " м\n";
	cout << "Время: " << minutes << " мин " << seconds << " сек = " << totalSeconds << " сек\n";
	cout << "Вы бежали со скоростью " << fixed << setprecision(2) << speed << " км/ч";
}

void task5() {
	double deposit, percent;

	cout << "Введите сумму вклада (евро): ";
	cin >> deposit;
	cout << "Введите процент годовых: ";
	cin >> percent;

	if (deposit < 0 || percent < 0) {
		cout << "Значения не могут быть отрицательными";
		return;
	}

	double monthly = deposit * percent / 100 / 12;

	cout << "Каждый месяц банк выплачивает: " << fixed << setprecision(2) << monthly << " евро";
}

int main() {
	setlocale(LC_ALL, "RU");
	int choice;

	cout << "Выберите задание (1-5): ";
	cin >> choice;

	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	case 5: task5(); break;
	default:
		cout << "Такого задания нет";
	}

	return 0;
}