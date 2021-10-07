#include <iostream>
using namespace std;
void bin(int a, int arr[], int arr_bin[], int& n) {
int znak = 0, j = 0;
n = 0;
if (a < 0) znak = 1;
a = abs(a);
while (a != 0) {
arr[n] = a%2;
a/=2;
n++;
}
arr_bin[0] = znak;
while (j < 7-n) {
arr_bin[j+1] = 0;
j++;
}
int i = j+1;
while (i < 8) {
arr_bin[i] = arr[7-i];
i++;
}
n = 8;
}

void obratny(int arr_bin[]) {
if (arr_bin[0] == 1) {
int i = 1;
while (i < 8) {
if (arr_bin[i] == 0) arr_bin[i] = 1;
else arr_bin[i] = 0;
i++;
}
}
}

void dop(int arr_bin[]) {
int plus = 1;
if (arr_bin[0] == 1) {
int i = 0;
while (i < 8) {
if ((arr_bin[8-i-1] + plus) == 2) {
arr_bin[8-i-1] = 0;
plus = 1;
}
else {
arr_bin[8-i-1] = 1;
plus = 0;
break;
}
i++;
}
}
}

int main() {
int a, arr[100], n, arr_bin[100];
cin » a;
bin(a, arr, arr_bin, n);
cout « "Бинарный: ";
int i = 0;
while (i < 8) {
cout « arr_bin[i];
i++;
}
i = 0;
cout « endl;
obratny(arr_bin);
cout « "Обратный: ";
while (i < 8) {
cout « arr_bin[i];
i++;
}
i = 0;
dop(arr_bin);
cout « endl;
cout « "Дополнительный: ";
while (i < 8) {
cout « arr_bin[i];
i++;
}

return 0;
}
