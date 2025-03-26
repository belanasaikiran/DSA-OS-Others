#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size){
   for(int i = 1; i < size; i++){
       int temp = arr[i];
       int j = i - 1;
       while(j > -1 && temp < arr[j]){ // order matter since arr[-1] throws the error for comparing.
           arr[j+1] = arr[j];
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
