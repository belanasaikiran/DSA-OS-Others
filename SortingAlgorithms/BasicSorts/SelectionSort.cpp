#include <iostream>

using namespace std;

// void SelectionSort(int arr[], int size){
//     for(int i = 0; i < size; i++){
//         int minIndex = i;
//         for(int j = i+1; j < size; j++){
//             if(arr[j] < arr[minIndex]){
//                 minIndex = j;
//             }
//         }
//         if(i != minIndex){ // no need to swap if i == minIndex
//             int temp = arr[i];
//             arr[i] = arr[minIndex];
//             arr[minIndex] = temp;
//         }
//     }
// }
//
//
//


void SelectionSort(int *arr, int &size){

    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex] ){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }



}

int main(){
    int arr[] = {4, 2, 6, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, size);

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
