#include <iostream>

using namespace std;


// Bubble sort - sorts the largest value to the last and reduces the loop for next one
void BubbleSort(int *arr, int &size){

    for(int i = size - 1; i > 0; --i){
        for(int j = 0; j < i; j++){ // after every loop, the size of comparision array becomes smaller.
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main() {
    int arr[] = {4, 2, 6, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr,size);

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
