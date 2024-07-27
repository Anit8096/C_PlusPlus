#include <iostream>
#include <algorithm> 

using namespace std;

int BinarySearch (int arr[], int start, int end, int find) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == find) {
            return mid;
        }

        (arr[mid] < find) 
            ? start = mid + 1
            : end = mid -1;
    }
    return -1;
}

int main(void) {
    int arr[] = { 2, 3, 4, 7, 9, 10, 40, 5, 8, 6, 0};
    int find = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n); 
    cout<<"Array after sorting : ";
    for (auto i : arr) {
        cout << i <<" ";
    }
    cout<<endl;cout<<"To Find : "<< find << endl;
    int result = BinarySearch(arr, 0, n - 1, find);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}