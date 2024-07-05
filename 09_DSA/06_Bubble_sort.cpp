#include <iostream>
#include <utility>

using namespace std;

void BubbleSort (int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n -1; i++){
        swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false) break;
    }
}

int main() {
    int arr[] = {34,1,7,56,31,77};
    int m = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,m);
    cout<<"Sorted Array -> ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] <<" ";
    }
}