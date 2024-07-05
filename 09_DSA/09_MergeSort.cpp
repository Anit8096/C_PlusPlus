#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to merge two halves of an array
void Merge(int arr[], int start, int middle, int end) {
    int Left_arr = middle - start + 1;
    int Right_arr = end - middle;

    int* leftSUBarray = new int[Left_arr];
    int* rightSUBarray = new int[Right_arr];

    for (int i = 0; i < Left_arr; i++) {
        leftSUBarray[i] = arr[start + i];
    }
    for (int j = 0; j < Right_arr; j++) {
        rightSUBarray[j] = arr[middle + 1 + j];
    }

    cout << "Merging arrays: ";
    for (int i = 0; i < Left_arr; i++) {
        cout << leftSUBarray[i] << " ";
    }
    cout << "and ";
    for (int j = 0; j < Right_arr; j++) {
        cout << rightSUBarray[j] << " ";
    }
    cout << endl;

    int IndexOfSubArray1 = 0;
    int IndexOfSubArray2 = 0;
    int IndexOfMergedArray = start;

    while (IndexOfSubArray1 < Left_arr && IndexOfSubArray2 < Right_arr) {
        if (leftSUBarray[IndexOfSubArray1] <= rightSUBarray[IndexOfSubArray2]) {
            arr[IndexOfMergedArray] = leftSUBarray[IndexOfSubArray1];
            IndexOfSubArray1++;
        } else {
            arr[IndexOfMergedArray] = rightSUBarray[IndexOfSubArray2];
            IndexOfSubArray2++;
        }
        IndexOfMergedArray++;
    }

    while (IndexOfSubArray1 < Left_arr) {
        arr[IndexOfMergedArray] = leftSUBarray[IndexOfSubArray1];
        IndexOfSubArray1++;
        IndexOfMergedArray++;
    }

    while (IndexOfSubArray2 < Right_arr) {
        arr[IndexOfMergedArray] = rightSUBarray[IndexOfSubArray2];
        IndexOfSubArray2++;
        IndexOfMergedArray++;
    }

    delete[] leftSUBarray;
    delete[] rightSUBarray;
}


// Function to sort an array using merge sort algorithm
void MergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

// Main function
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is -> ";
    printArray(arr, arr_size);
    cout << endl;

    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is -> ";
    printArray(arr, arr_size);

    return 0;
}
