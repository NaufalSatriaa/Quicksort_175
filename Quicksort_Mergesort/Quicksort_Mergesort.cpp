#include <iostream>
using namespace std;

int arr[20]; //array of integres to hold values
int cmp_count = 0;// number of comparasion
int mov_count = 0;// number of movement
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
// swap the element at index x with the element index y
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

	// partition the list into two parts
	// one centaining element less that or equal to pivot
	// outher containing element greather than pivot
	i = low + 1;
	j = high;
	pivot = arr[low];

	while (i <= j) {
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high)) {
			i++;
			cmp_count++;
		}
		cmp_count++;
		///search for an element less thanor equal to pivot
		while ((arr[j] > pivot) && (j >= low)) {
			j--;
			cmp_count++;
		}
	}
	cmp_count++;
	if (i < j) {//if greater element is on left of the element
		
		//swap the element at index i with the element at index j
		swap(i, j);
		mov_count++;
	}//j now containt the index of the last element in the sort list
	if (low < j) {
		//move to the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}//sort the list on the left of pivot using quick sort
	q_sort(low, j - 1);
	//short the list on the right of pivot using quizl sort
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