#include <iostream>

using namespace std;

void InsertionSort(int *arr, int &size){
    //  like a pack of cards
    // start with second card/element and check with first one.
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i - 1;
        while(temp < arr[j]){
            arr[j+1] = arr[j]; // swap but note -> initially, arr[j+1] could be arr[i] itself but the j keeps changing in this loop
            arr[j] = temp;
            j--;
        }
    }


}

int main(){
    int arr[] = {4, 2, 6, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, size);

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
