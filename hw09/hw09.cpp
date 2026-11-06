#include <iostream>

using namespace std;

int w1() {
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    for (; a <= b; a++) {
        cout << "Делители для числа " << a << " - ";
        for (int i = 1; i <= b; i++) {
            if (a % i == 0) {
                cout << a / i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

int w2() {
    for (int i = 2; i <= 1000; i++) {
        bool simple = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                simple = false;
                break;
            }
        }
        if (simple) {
            cout << i << " ";
        }
    }
    return 0;
}

int w3() {
	int n;
    cout << "Введите любое нечётное число: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j) || (i+j == n - 1) || ( n / 2 == i) || (n / 2 == j)) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    return 0; 
}

int w4() {
    int numbers = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (k != j && j != i && k != i) {
					cout << i << j << k << " ";
                    numbers++;
                }
            }
        }
    }
    cout << "Количество трёхзначных чисел: " << numbers << endl;
    return 0;
}

int w5() {
    int sum = 0, second;
	int arrSum[12] = {0};
    for (int g = 0; g < 3; g++) {
        for (int h = 0; h < 12; h++) {
            cout << "Выплата сотруднику " << h+1 << " за ";
            switch (g) {
            case 0: cout << "Март: "; break;
            case 1: cout << "Апрель: "; break;
            case 2: cout << "Май: "; break;
            }
			cin >> second;
            arrSum[h] = arrSum[h] + second;
        }
    }
	for (int i = 0; i < 12; i++) {
		cout << "Сумма выплат сотруднику " << i + 1 << " за 3 месяца: " << arrSum[i] << endl;
        sum += arrSum[i];
	}
    cout << "Сумма выплат: " << sum << endl;
    return 0;
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
