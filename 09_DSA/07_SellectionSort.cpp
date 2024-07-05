#include <iostream>
#include <utility>
using namespace std;

void SellectionSort(int arr[], int size) {
    int MIN_index;
    for (int i = 0; i < size-1; i++) {
        MIN_index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[MIN_index] > arr[j]) {
                MIN_index = j;
            }
        }
        if (MIN_index != i) {
            swap(arr[MIN_index],arr[i]);
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i == size-1) {cout<<endl;}
    }
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    SellectionSort(arr, n);
    cout << "Sorted array -> ";
    printArray(arr, n);
    return 0;
}