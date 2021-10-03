#include <iostream>
using namespace std;
void bin(int a, int arr[], int arr_bin[], int& n) {
	int znak = 0, j = 0;
	n = 0;
	if (a < 0) znak = 1;
	a = abs(a);
	while (a != 0) {
		arr[n] = a % 2;
		a /= 2;
		n++;
	}
	arr_bin[0] = znak;
	while (j < 7 - n) {
		arr_bin[j + 1] = 0;
		j++;
	}
	for (int i = j + 1; i < 8; i++) {
		arr_bin[i] = arr[7 - i];
	}
	n = 8;
}

void obratny(int arr_bin[]) {
	if (arr_bin[0] == 1) {
		for (int i = 1; 8 != i; i++) {
			if (arr_bin[i] == 0) arr_bin[i] = 1;
			else arr_bin[i] = 0;
		}
	}
}

void dop(int arr_bin[]) {
	int plus = 1;
	if (arr_bin[0] == 1) {
		for (int i = 0; i != 8; i++) {
			if ((arr_bin[8 - i - 1] + plus) == 2) {
				arr_bin[8 - i - 1] = 0;
				plus = 1;
			}
			else {
				arr_bin[8 - i - 1] = 1;
				plus = 0;
				break;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a, arr[100], n, arr_bin[100];
	cin >> a;
	bin(a, arr, arr_bin, n);
	cout << "Бинарный: ";
	for (int i = 0; i != n; i++) {
		cout << arr_bin[i];
	}
	cout << endl;
	obratny(arr_bin);
	cout << "Обратный: ";
	for (int i = 0; i != n; i++) {
		cout << arr_bin[i];
	}
	dop(arr_bin);
	cout << endl;
	cout << "Дополнительный: ";
	for (int i = 0; i != n; i++) {
		cout << arr_bin[i];
	}
	return 0;
}