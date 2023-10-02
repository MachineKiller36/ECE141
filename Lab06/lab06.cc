#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include "HeapSortHeader2.h"



using namespace std;



void displayMenu() {
	cout << "\nMenu:\n";
	cout << "1. Display the array\n";
	cout << "\n---Maximum Heap---\n";
	cout << "2. Ascending Heap Sort\n";
	cout << "3. Modify a maximum value\n";
	cout << "4. Insert a maximum value\n";
	cout << "5. Extract maximum\n";
	cout << "\n---Minimum Heap---\n";
	cout << "6. Descending Heap Sort\n";
	cout << "7. Modify a minimum value\n";
	cout << "8. Insert a minimum value\n";
	cout << "9. Extract minimum\n";
	cout << "10. Exit\n";
}


void handleUserInput(Heap heap) {
	int choice;
	while (true) {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;


		switch (choice) {
			case 1:
				{
					cout << "Current array: ";
					heap.printArray();
					break;
				}
			case 2:
				{
					heap.ascendingHeapSort();
					cout << "Array sorted in ascending order: ";
					heap.printArray();
					break;
				}
			case 3:
				{
					int index, val;
					cout << "Enter the index to modify: ";
					cin >> index;
					cout << "Enter the new value: ";
					cin >> val;
					heap.modifyValMax(index, val);
					cout << "Array after modification: ";
					heap.printArray();
					break;
				}
			case 4:
				{
					int newVal;
					cout << "Enter the new value to insert: ";
					cin >> newVal;
					heap.insert_value_maxHeap(newVal);
					cout << "Array after insertion: ";
					heap.printArray();
					break;
				}
			case 5:
				{
					int max_val = heap.extract_maximum();
					if (max_val != -1){
						cout << "Max value extracted: " << max_val << "\n";
					}
					else{
						cout << "Heap is empty.\n";
					}
					break;
				}
			case 6:
				{
					heap.descendingHeapSort();
					cout << "Array sorted in descending order: ";
					heap.printArray();
					break;

				}
			case 7:
				{
					int index, val;
					cout << "Enter the index to modify: ";
					cin >> index;
					cout << "Enter the new value: ";
					cin >> val;
					heap.modifyValMin(index, val);
					cout << "Array after modification: ";
					heap.printArray();
					break;

				}
			case 8:
				{
					int newVal;
					cout << "Enter the new value to insert: ";
					cin >> newVal;
					heap.insert_value_minHeap(newVal);
					cout << "Array after insertion: ";
					heap.printArray();
					break;

				}
			case 9:
				{
					int min_val = heap.extract_minimum();
					if (min_val != -1){
						cout << "Min value extracted: " << min_val << "\n";
					}
					else{
						cout << "Heap is empty.\n";
					}
					break;

				}
			case 10:
				{
					return;
				}
			default:
				{
					cout << "Invalid choice. Try again.\n";
				}
		}
	}
}


int main() {
	int n;
	cout << "Enter the size of the array: \n";
	cin >> n;


	Heap heap(n);

	cout << "Enter 1, to generate random numbers, or Enter 0, to input your own numbers?\n";
	int inputChoice;
	cin >> inputChoice;

	cout << "Enter 1, for values to be Max Heap Inserted, or Enter 0, for values to be Min Heap Inserted\n";
	int select = 0;
	cin >> select;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1000);


	if (inputChoice) {
		cout << "Random array: ";
		for (int i = 0; i < n; i++) {
			int value = dis(gen);
			if(select) heap.insert_value_maxHeap(value);
			else heap.insert_value_minHeap(value);
			cout << value << " ";
		}
		cout << endl;
	} else {
		cout << "Enter the elements of the array:" << endl;
		for (int i = 0; i < n; i++) {
			cout << "Enter element " << i + 1 << ": ";
			int element = 0;
			cin >> element;
			if(select) heap.insert_value_maxHeap(element);
			else heap.insert_value_minHeap(element);
		}
	} 
	handleUserInput(heap);
}

