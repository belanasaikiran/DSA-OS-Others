#include <iostream>

void Printer(int arr[], int n);

void InsertionSort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i]; // considering the second element
		int j = i - 1; // need this for comparing the element - get the first element or the one before the key element.

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		Printer(arr, n);
	}
}

void Printer(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i];
		if (i < n - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

}




int main() {
	std::cout << "Insertion Sort: " << std::endl;

	int arr[] = { 12, 11, 4, 9, 2 };
	int n = sizeof(arr) / sizeof(arr[0]); // sizeof tells the bit size so we divide it by first index -> 20/4 = 5
	Printer(arr, n);
	InsertionSort(arr, n);
	std::cin.get();
}