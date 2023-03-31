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

void q_sort(int low, int high) {
	int pivot, i, j;
	if (low > high)
		return;

	i = low + 1;
	j = high;
	pivot = arr[low];

	while (i <= j) {
		while ((arr[i] <= pivot) && (i <= high)) {
			i++;
			cmp_count++;
		}
		cmp_count++;
		while ((arr[j] > pivot) && (j >= low)) {
			j--;
			cmp_count++;
		}
	}
	cmp_count++;
	if (i < j) {
		swap(i, j);
		mov_count++;
	}
	if (low < j) {
		swap(low, j);
		mov_count++;
	}
	q_sort(low, j - 1);
	q_sort(j + 1, high);
}

void display() {
	cout << "\n------------" << endl;
	cout << "\nsorted array" << endl;
	cout << "\n------------" << endl;
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\nnumber of comparison : " << cmp_count << endl;
	cout << "number of data movement : " << mov_count << endl;
}

int main() {
	input();
		q_sort(0, n - 1);
	display();
	system("pause");

	return 0;

}