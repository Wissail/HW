#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void task1() {
	double pizzaPrice1 = 6.75, pizzaPrice2 = 8.95, pizzaPrice3 = 14.5, pizzaPrice4 = 10.25;
	double drinkPrice1 = 1.79, drinkPrice2 = 2.5, drinkPrice3 = 3.09;
	int pizzaID, drinkID, pizzaAmount = 0, drinkAmount = 0;
	double selPizPrice = 0, selDrPrice = 0;
	string pizzaName, drinkName;

	cout << fixed << setprecision(2);

	cout << "Пиццы:\n";
	cout << "1 - Сырная $" << pizzaPrice1 << "\n";
	cout << "2 - Гавайская $" << pizzaPrice2 << "\n";
	cout << "3 - Барбекю $" << pizzaPrice3 << "\n";
	cout << "4 - С морепродуктами $" << pizzaPrice4 << "\n";
	cout << "0 - Без пиццы\n";
	cout << "Введите код пиццы: ";
	cin >> pizzaID;

	switch (pizzaID) {
	case 0:
		break;
	case 1: pizzaName = "Сырная"; selPizPrice = pizzaPrice1; break;
	case 2: pizzaName = "Гавайская"; selPizPrice = pizzaPrice2; break;
	case 3: pizzaName = "Барбекю"; selPizPrice = pizzaPrice3; break;
	case 4: pizzaName = "С морепродуктами"; selPizPrice = pizzaPrice4; break;
	default: cout << "Такой пиццы нет"; return;
	}

	if (pizzaID != 0) {
		cout << "Введите количество: ";
		cin >> pizzaAmount;
		if (pizzaAmount <= 0) {
			cout << "Количество должно быть больше нуля";
			return;
		}
	}

	cout << "\nНапитки:\n";
	cout << "1 - Кола $" << drinkPrice1 << "\n";
	cout << "2 - Сок $" << drinkPrice2 << "\n";
	cout << "3 - Лимонад $" << drinkPrice3 << "\n";
	cout << "0 - Без напитка\n";
	cout << "Введите код напитка: ";
	cin >> drinkID;

	switch (drinkID) {
	case 0:
		break;
	case 1: drinkName = "Кола"; selDrPrice = drinkPrice1; break;
	case 2: drinkName = "Сок"; selDrPrice = drinkPrice2; break;
	case 3: drinkName = "Лимонад"; selDrPrice = drinkPrice3; break;
	default:
		cout << "Такого напитка нет";
		return;
	}

	if (drinkID != 0) {
		cout << "Введите количество: ";
		cin >> drinkAmount;
		if (drinkAmount <= 0) {
			cout << "Количество должно быть больше нуля";
			return;
		}
	}

	if (pizzaID == 0 && drinkID == 0) {
		cout << "Заказ пустой";
		return;
	}

	int freePizzas = pizzaAmount / 5;
	double pizzaSum = (pizzaAmount - freePizzas) * selPizPrice;

	double drinkSum = drinkAmount * selDrPrice;
	bool drinkDiscount = selDrPrice > 2 && drinkAmount > 3;
	if (drinkDiscount) {
		drinkSum = drinkSum * (1 - 15.0 / 100);
	}

	double sumOrder = pizzaSum + drinkSum;
	bool orderDiscount = sumOrder > 50;
	double toPay = sumOrder;
	if (orderDiscount) {
		toPay = sumOrder * (1 - 20.0 / 100);
	}

	cout << "\n===== ЧЕК =====\n";
	if (pizzaID != 0) {
		cout << "Пицца " << pizzaName << " - " << pizzaAmount << " шт - $" << pizzaSum << "\n";
		if (freePizzas > 0) {
			cout << "  (из них " << freePizzas << " шт в подарок)\n";
		}
	}
	if (drinkID != 0) {
		cout << drinkName << " - " << drinkAmount << " шт - $" << drinkSum << "\n";
		if (drinkDiscount) {
			cout << "  (скидка 15% на напитки)\n";
		}
	}
	cout << "Сумма заказа: $" << sumOrder << "\n";
	if (orderDiscount) {
		cout << "Скидка 20%: -$" << sumOrder - toPay << "\n";
	}
	cout << "Итого к оплате: $" << toPay;
}

void task2() {
	double sales1, sales2, sales3;

	cout << "Введите уровень продаж 1-го менеджера: ";
	cin >> sales1;
	cout << "Введите уровень продаж 2-го менеджера: ";
	cin >> sales2;
	cout << "Введите уровень продаж 3-го менеджера: ";
	cin >> sales3;

	if (sales1 < 0 || sales2 < 0 || sales3 < 0) {
		cout << "Продажи не могут быть отрицательными";
		return;
	}
	if (sales1 == sales2 || sales1 == sales3 || sales2 == sales3) {
		cout << "Уровень продаж у всех менеджеров должен быть разный";
		return;
	}

	double salary1, salary2, salary3;

	if (sales1 < 500) {
		salary1 = 200 + sales1 * 3 / 100;
	}
	else if (sales1 <= 1000) {
		salary1 = 200 + sales1 * 5 / 100;
	}
	else {
		salary1 = 200 + sales1 * 8 / 100;
	}

	if (sales2 < 500) {
		salary2 = 200 + sales2 * 3 / 100;
	}
	else if (sales2 <= 1000) {
		salary2 = 200 + sales2 * 5 / 100;
	}
	else {
		salary2 = 200 + sales2 * 8 / 100;
	}

	if (sales3 < 500) {
		salary3 = 200 + sales3 * 3 / 100;
	}
	else if (sales3 <= 1000) {
		salary3 = 200 + sales3 * 5 / 100;
	}
	else {
		salary3 = 200 + sales3 * 8 / 100;
	}

	int best;
	if (sales1 > sales2 && sales1 > sales3) {
		best = 1;
		salary1 += 200;
	}
	else if (sales2 > sales3) {
		best = 2;
		salary2 += 200;
	}
	else {
		best = 3;
		salary3 += 200;
	}

	cout << fixed << setprecision(2);
	cout << "\nЗарплата 1-го менеджера: $" << salary1 << "\n";
	cout << "Зарплата 2-го менеджера: $" << salary2 << "\n";
	cout << "Зарплата 3-го менеджера: $" << salary3 << "\n";
	cout << "Лучший менеджер: " << best << "-й, ему начислена премия $200";
}

int main() {
	setlocale(LC_ALL, "RU");
	int choice;

	cout << "Выберите задание (1-2): ";
	cin >> choice;

	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	default:
		cout << "Такого задания нет";
	}

	return 0;
}