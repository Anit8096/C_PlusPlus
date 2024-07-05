#include<iostream>
using namespace std;

int search(int arr[], int size, int toFind)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == toFind)
            return i;
    return -1;
}

int main(void) {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x;
    cout<<"Enter value to search -> ";
    cin>>x;
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}