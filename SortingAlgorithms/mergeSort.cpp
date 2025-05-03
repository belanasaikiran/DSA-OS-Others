#include <iostream>
#include <vector>
using namespace std;

class Sort {

public:
  // Divide and Conquer - We divide the array into smaller arrays here
  // Break and Break in half - Recursively
  void mergeSort(vector<int> &array, int leftIndex, int rightIndex) {

    // Base Step:
    if (leftIndex >= rightIndex)
      return; // break here

    // priority for divide -> Eg: mid = 0 + (6- 0) / 2 = 3
    // where left = 0, right = 6
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    // The Below are recursive step initializers
    // Recursive Step:
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex, rightIndex);

    //  Call the merge step function
    merge(array, leftIndex, midIndex, rightIndex);
  }

  // Merge Step - this should be the helper - runs in MergeSort()
  void merge(vector<int> &array, int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    // memory creation
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
      leftArray[i] = array[leftIndex + i]; // fill the memory

    for (int j = 0; j < rightArraySize; j++)
      rightArray[j] = array[midIndex + 1 + j];

    // We need to merge the arrays here
    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize) {
      if (leftArray[i] <= rightArray[j]) {
        array[index] = leftArray[i];
        i++;
        index++;
      } else {
        array[index] = rightArray[j];
        j++;
        index++;
      }
    }

    //  left overs on left array and right array. Just append them to the main
    //  array
    while (i < leftArraySize) {
      array[index] = leftArray[i];
      i++;
      index++;
    }

    while (j < rightArraySize) {
      array[index] = rightArray[j];
      j++;
      index++;
    }
  }
};

int main() {

  vector<int> input = {5, 4, 7, 1, 3, 2, 8, 6};
  vector<int> input2 = {1, 3, 7, 8, 2, 4, 5, 6};

  int size = input2.size();
  int leftIndex = 0;
  int rightIndex = size - 1;
  int midIndex = (size / 2) - 1;

  Sort *MergeSort = new Sort;
  MergeSort->merge(input2, leftIndex, midIndex, rightIndex);

  for (auto value : input2) {
    cout << value << " ";
  }

  cout << endl;

  return 0;
}
