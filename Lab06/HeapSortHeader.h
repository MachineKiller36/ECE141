#include <iostream>

using namespace std;

struct Heap {
    int Arr[];
    Heap();

    void printArray(int Arr[],int n);

     //Max heap
    void modifyValMax (int Arr[], int n, int i,int val); //Modify value
    void insert_value_maxHeap (int Arr[], int val, int& n); //Adds value at the end of array and calls max_heapify
    void max_heapify(int Arr[], int i,int n); //Maintains the max heap property
    int extract_maximum (int Arr[], int& n); //Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(int Arr[], int n); //Prints the array in ascending order
    void buildMaxHeap(int Arr[], int n); //Heapifies entire list


    //Min Heap
    void modifyValMin (int Arr[], int n, int i,int val); //Modify value
    void insert_value_minHeap (int Arr[], int val, int& n); // Adds value at the end of array and calls min_heapify
    void min_heapify(int Arr[], int i); //Maintains min heap property
    int extract_minimum (int Arr[]); //Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(int Arr[], int n); //Prints the array in descending order
    void buildMinHeap(int Arr[], int n); //Heapifies entire list
};
