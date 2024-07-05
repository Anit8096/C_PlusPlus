#include <iostream>
using namespace std;

void InsertionSort (int arr[], int n) {
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
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

    InsertionSort(arr, n);
    cout << "Sorted array -> ";
    printArray(arr, n);
    return 0;
}