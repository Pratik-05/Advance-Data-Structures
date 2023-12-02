#include <iostream>
using namespace std;

// Print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
        cout << "\n"<< "From Heapify :- ";
        printArray(arr, n);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap

    cout << "\n Build Heap :- ";
    for (int i = n / 2 - 1; i >= 0; i--)   //   
            heapify(arr, n, i);

    cout << "\n Heap Sort :- ";
    cout << "\n Heap is :- ";
    printArray(arr, n);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        cout << "\n"
             << i << "th Pass :- ";
        printArray(arr, n);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);

        cout << "\n"
             << i << "th Pass After Heapiy :- ";
        printArray(arr, n);
    }
}

// Driver code
int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorting :- \n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Array AFter Sorting is :- \n";
    printArray(arr, n);
}

/*
Array Before Sorting :- 
1 12 9 5 6 10 

 Build Heap :- 
From Heapify :- 1 12 10 5 6 9 

From Heapify :- 12 6 10 5 1 9 

From Heapify :- 12 6 10 5 1 9 

 Heap Sort :- 
 Heap is :- 12 6 10 5 1 9 

5th Pass :- 9 6 10 5 1 12 

From Heapify :- 10 6 9 5 1 

5th Pass After Heapiy :- 10 6 9 5 1 12 

4th Pass :- 1 6 9 5 10 12 

From Heapify :- 9 6 1 5 

4th Pass After Heapiy :- 9 6 1 5 10 12 

3th Pass :- 5 6 1 9 10 12 

From Heapify :- 6 5 1 

3th Pass After Heapiy :- 6 5 1 9 10 12 

2th Pass :- 1 5 6 9 10 12 

From Heapify :- 5 1 

2th Pass After Heapiy :- 5 1 6 9 10 12 

1th Pass :- 1 5 6 9 10 12 

1th Pass After Heapiy :- 1 5 6 9 10 12 

0th Pass :- 1 5 6 9 10 12 

0th Pass After Heapiy :- 1 5 6 9 10 12 
Array AFter Sorting is :- 
1 5 6 9 10 12 
*/