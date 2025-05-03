#include <iostream>

using namespace std;

class QuickSort {

public:
  void quickSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
      return;

    int pivotIndex = pivot(arr, leftIndex, rightIndex);

    quickSort(arr, leftIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, rightIndex);
  }

  int pivot(int arr[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
      if (arr[i] < arr[pivotIndex]) {
        swapIndex++;
        swap(arr, swapIndex, i);
      }
    }
    swap(arr, pivotIndex, swapIndex);

    return swapIndex;
  };

  void swap(int arr[], int firstIndex, int secondIndex) {
      int temp = arr[firstIndex];
      arr[firstIndex] = arr[secondIndex];
      arr[secondIndex] = temp;
  }
};

int main() {

  int arr[] = {4, 6, 1, 7, 3, 2, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  QuickSort *sort = new QuickSort();

  // int returnedIndex = sort->pivot(arr, 0, size - 1);
  // cout << "Returned Index: " << returnedIndex << "\n\n";

  sort->quickSort(arr, 0, size - 1);


  for(auto value : arr){
      cout << value << " ";
  }
  cout << endl;


  return 0;
}
