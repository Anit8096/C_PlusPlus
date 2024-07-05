#include<iostream>
using namespace std;

void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex;
    int left = 2*rootIndex+1;
    int right = 2*rootIndex+2;

    if (left < size && arr[left] > arr[largest]) 
        largest = left;
    
    if (right < size && arr[right] > arr[largest]) 
        largest = right;
    
    if (largest != rootIndex) {
        swap(arr[rootIndex] ,arr[largest]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int arr[], int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}