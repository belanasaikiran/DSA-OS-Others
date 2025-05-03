#include <any>
#include <iostream>

using namespace std;

int pivot(int arr[], int pivotIndex, int endIndex);
void swap(int arr[], int left, int right);

void quickSort(int arr[], int left, int right) {
  if (right <= left)
    return; // base case

  int pivotIndex = pivot(arr, left, right);

  quickSort(arr, left, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, right);
};

int pivot(int arr[], int pivotIndex, int endIndex) {
  int swapindex = pivotIndex;

  for (int j = pivotIndex + 1; j <= endIndex; j++) {
    if (arr[j] < arr[pivotIndex]) {
      swapindex++; // this increment tells us how many steps we have to move
                   // from start to get to the middle of array or at a location
                   // where pivot is properly sorted such that all elements left
                   // of pivot are smaller and all elements right of pivot are
                   // larger.
      swap(arr, swapindex, j);
    }
  };
  swap(arr, pivotIndex, swapindex); // swap the pivot index with the swapindex we just calculated
  return swapindex;
};

void swap(int arr[], int left, int right) {
  int swap = arr[left];
  arr[left] = arr[right];
  arr[right] = swap;
};

int main() {

  int arr[] = {9, 5, 7, 3, 8, 2, 6, 1};
  int right = (sizeof(arr) / sizeof(arr[0])) - 1;

  quickSort(arr, 0, right);

  return 0;
}
