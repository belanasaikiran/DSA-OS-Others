#include <iostream>

struct Sorting{
    void quickSort(int arr[], int left, int right){
        if(right <= left) return;

        int pivot = pivotIndex(arr, left, right);
        quickSort(arr, left, pivot);
        quickSort(arr, pivot+1, right);

    }

    int pivotIndex(int arr[], int pivotIndex, int right){

        int swapIndex = pivotIndex;
        for(int i = pivotIndex + 1; i < right; i++){
            if(arr[i] < arr[pivotIndex]){
                swapIndex++;
                swap(arr, swapIndex, i);
            }
        }
        swap(arr, swapIndex, pivotIndex);
        return swapIndex;
    }

    void swap(int arr[], int left, int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    void printArr(int arr[], int size){
        std::cout <<  "[ ";
        for(int i = 0; i <  size; i++){
            if(i != size - 1) std::cout << arr[i] << ", ";
            else std::cout << arr[i] << "]";
        }
    }
};

int main(){
    int arr[] = {9, 7, 2, 5, 6, 1, 4, 3};

    int right = sizeof(arr)/sizeof(arr[0]);

    Sorting* sorter = new Sorting;
    sorter->quickSort(arr, 0, right);
    sorter->printArr(arr, right);

    return 0;
}
