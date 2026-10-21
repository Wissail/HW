#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void task1() {
	string numbers;

	cout << "введите 6 цифр\n";
	cin >> numbers;

	if (numbers.length() != 6) {
		cout << "Нужно вести ровно 6 цифр";
		return;
	}

	int* nums = new int[numbers.length()];

	for (int i = 0; i < 6; i++) {
		if (!isdigit(numbers[i])) {
			cout << "Вы ввели не цифры";
			delete[] nums;
			return;
		}
		else {
			nums[i] = numbers[i] - '0';
		}
	}

	int sum1 = nums[0] + nums[1] + nums[2];
	int sum2 = nums[3] + nums[4] + nums[5];

	if (sum1 == sum2) {
		cout << "У вас счастливое число";
	}
	else {
		cout << "У вас не счастливое число";
	}

	delete[] nums;
}

void task2() {
	string numbers;

	cout << "введите 4 цифр\n";
	cin >> numbers;

	if (numbers.length() != 4) {
		cout << "Нужно вести ровно 4 цифр";
		return;
	}

	int* nums = new int[numbers.length()];

	for (int i = 0; i < 4; i++) {
		if (!isdigit(numbers[i])) {
			cout << "Вы ввели не цифры";
			delete[] nums;
			return;
		}
		else {
			nums[i] = numbers[i] - '0';
		}
	}
	int numsres[4] = { nums[1], nums[0], nums[3], nums[2] };

	for (int i = 0; i < 4; i++) {
		cout << numsres[i];
	}

	delete[] nums;
}

void task3() {
	string numbers;
	int bigest = 0;

	cout << "введите 7 цифр\n";
	cin >> numbers;

	if (numbers.length() != 7) {
		cout << "Нужно вести ровно 7 цифр";
		return;
	}

	int* nums = new int[numbers.length()];

	for (int i = 0; i < 7; i++) {
		if (!isdigit(numbers[i])) {
			cout << "Вы ввели не цифры";
			delete[] nums;
			return;
		}
		else {
			nums[i] = numbers[i] - '0';
		}
	}

	for (int i = 0; i < 7; i++) {
		if (bigest < nums[i]) {
			bigest = nums[i];
		}
	}
	cout << bigest;

	delete[] nums;
}

void task4() {
	const int TANK = 300;
	double distAB, distBC, weight;
	int perKm;

	cout << "Введите расстояние от A до B (км): ";
	cin >> distAB;
	cout << "Введите расстояние от B до C (км): ";
	cin >> distBC;
	cout << "Введите вес груза (кг): ";
	cin >> weight;

	if (distAB < 0 || distBC < 0 || weight < 0) {
		cout << "Значения не могут быть отрицательными";
		return;
	}

	if (weight <= 500) {
		perKm = 1;
	}
	else if (weight <= 1000) {
		perKm = 4;
	}
	else if (weight <= 1500) {
		perKm = 7;
	}
	else if (weight <= 2000) {
		perKm = 9;
	}
	else {
		cout << "Самолет не поднимает больше 2000 кг, полет невозможен";
		return;
	}

	double fuelAB = distAB * perKm;
	double fuelBC = distBC * perKm;

	if (fuelAB > TANK || fuelBC > TANK) {
		cout << "Полет по этому маршруту невозможен: не хватает объема бака";
		return;
	}

	double leftAtB = TANK - fuelAB;
	double refuel = fuelBC - leftAtB;
	if (refuel < 0) {
		refuel = 0;
	}

	cout << "Минимальная дозаправка в пункте B: " << refuel << " л";
}

int main() {
	setlocale(LC_ALL, "RU");
	int choice;

	cout << "Выберите задание (1-4): ";
	cin >> choice;

	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	default:
		cout << "Такого задания нет";
	}

	return 0;
}