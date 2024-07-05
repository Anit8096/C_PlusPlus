#include <iostream>
using namespace std;

int Partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start -1;

    for (int j = start; j<=end-1; j++) {
        if (arr[j] > pivot) {
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[end]);
    return i+1;
}

void QuickSort (int arr[], int start, int end) {
    if(start < end) {
        int partition = Partition(arr, start, end);
        QuickSort(arr,start,partition-1);
        QuickSort(arr,partition+1,end);
    }
}

int main() {
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // Function call
    QuickSort(arr,0,n-1);
    //Print the sorted array
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}