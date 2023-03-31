#include <iostream>
using namespace std;

int arr[20]; 
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true) {
		cout << "masukkan panjang element array" << endl;
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nmaksimum panjang array adalah 20" << endl;
	}

	cout << "---------------------" << endl;
	cout << "\nenter array element" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

void swap(int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
