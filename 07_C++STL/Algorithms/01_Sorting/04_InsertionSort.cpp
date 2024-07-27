#include <bits/stdc++.h> 
using namespace std; 

// Function to sort an array using insertion sort 
void insertionSort(int arr[], int n) { 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 
		// Move elements of arr[0..i-1], that are greater than key, to one 
		// position ahead of their current position 
		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) { 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() { 
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
	int N =10; 

	insertionSort(arr, N); 
	cout<<"array after using insertion sort:"<<endl; 
	printArray(arr, N); 

	return 0; 
} 

//This code is contributed by Machhaliya Muhammad
