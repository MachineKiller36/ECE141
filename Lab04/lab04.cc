#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include "Timer.h"

void merge(int array[], int bottom, int mid, int top) {
	int n1 = mid-bottom+1; 	 // Left subarray size
	int n2 = top-mid;   	 // Right subarray size
	// New subarrays
	int L[n1];		
	int R[n2];
	
	// Copys the array into the subarrays
	for(int it = 0; it < n1; it++) {
		L[it] = array[bottom+it];
	}
	for(int it = 0; it < n2; it++) {
		R[it] = array[mid+1+it];
	}
/*
 	Psuedo code does NOT work!
 	
	L[n1-1] = INT_MAX;
	R[n2-1] = INT_MAX;
	
	int i = 0;
	int j = 0;

	for(int k = bottom; k < top; k++) {
		if(L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		} else {
			array[k] = R[j];
			j++;
		}
	}
*/
	int i = 0;	// Holds the left subarrays index
	int j = 0;	// Holds the right subarrays index
	int k = bottom;	// Holds the main array index
	
	// Will loop through and initially swap the value until one of the subarray index's maxs out
	for(;(i < n1) && (j < n2); k++) {
		if(L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		} else {
			array[k] = R[j];
			j++;
		}
	}
	// Each of these loops finishes adding the subarrays vaules into the main array
	while(i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
}


void recursive(int array[], int bottom, int top) {
	if(bottom >= top)				// Invariant and Base case to stop the recursion
		return;
	int mid = bottom + (top - bottom)/2;		// Finds the middle index of the array
	recursive(array,bottom,mid);			// Divides the array into a subarray with the lower half of its values in the subarray
	recursive(array,mid+1,top);			// Divides the array into a subarray with the uppper half of its values in the subarray
	merge(array, bottom, mid, top);
}

int main() {
	Timer time;
	//// User Interface ///////////	
	while(true) {
		std::cout << "Enter the size of the array you want to test:\n\t! Entering a negative or a zero stops manual input section !\n> ";
		int user_size = 0;
		std::cin >> user_size;
		if(user_size < 1) break;

		int user_array[user_size];

		std::cout << "Enter a positive value to manual input elements or enter a negative to randomize inputs:\n > ";
		int user_choice = 0;
		std::cin >> user_choice;

		// Randomizes values and adds them into the array
		if(user_choice < 0) {
			std::srand(std::time(0));
			for(int index = 0; index < user_size; index++) {
				long long int value = (std::rand() & 1000) + 1;
				user_array[index] = value;
			}	
		// User manual input values into the array
		} else {
			for(int index = 0; index < user_size; index++) {
				std::cout << "Enter a value for the array at index " << index << "\n > ";
				long long int user_element = 0;
				std::cin >> user_element;
				user_array[index] = user_element;
			}
		}
		// Prints the initial array
		std::cout << "\nInitial Array\n";
		for(int i = 0; i < user_size; i++)
			std::cout << user_array[i] << "\t";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n\nMerge sort:\n";
		time.start();				// Starts timer
		recursive(user_array,0,user_size-1);	// Runs array through merge sort algorithm
		time.stop();				// Stops timer
		// Prints the final array
		std::cout << "\nFinal Array\n";
		for(int i = 0; i < user_size; i++)
			std::cout << user_array[i] << "\t";
		// Prints the time taken by the algorithm
		std::cout << "\nTime taken: " << time.get_time_nano() << " ns\n\n\n";
	}
	//// Test Bench ////
	int short_sorted[10];
	int short_half[10];
	int short_reverse[10];
	
	int medium_sorted[50];
	int medium_half[50];
	int medium_reverse[50];
	
	int long_sorted[100];
	int long_half[100];
	int long_reverse[100];
	// Primes Sorted Arrays //
	for(int i = 0; i < 100; i++) {
		if(i < 10) {
			short_sorted[i] = i;
		}
		if(i < 50) {
			medium_sorted[i] = i;
		}
		if(i < 100) {
			long_sorted[i] = i;
		}
	}
	// Primes Reverse Sorted Arrays //
	int value1 = 10;
	int value2 = 50;
	int value3 = 100;
	for(int i = 0; i < 100; i++) {
		if(i < 10) {
			short_reverse[i] = value1;
		}
		if(i < 50) {
			medium_reverse[i] = value2;
		}
		if(i < 100) {
			long_reverse[i] = value3;
		}
		value1--;
		value2--;
		value3--;
	}
	// Primes Half Sorted Arrays //
	value1 = 10;
	for(int i = 0; i < 10; i++) {
		if(i < 5) {
			short_half[i] = i;
		} else {
			short_half[i] = value1;
			value1--;
		}
	}
	value2 = 50;
	for(int i = 0; i < 50; i++) {
		if(i < 25) {
			medium_half[i] = i;
		} else  {
			medium_half[i] = value2;
			value2--;
		}
	}
	value3 = 100;
	for(int i = 0; i < 100; i++) {
		if(i < 50) {
			long_half[i] = i;
		} else {
			long_half[i] = value3;
			value3--;
		}
	}
	// Time comparison //
//// Sorted Tests ////
	std::cout << "\n\n\n\tSorted\n\nLength\t|\tMerge\n";
	time.start();
	recursive(short_sorted,0,9);
	time.stop();
	double merge_time = time.get_time_micro();
	std::cout << "Short\t|\t " << merge_time << " us\n";

	time.start();
	recursive(medium_sorted,0,49);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Medium\t|\t " << merge_time << " us\n";

	time.start();
	recursive(long_sorted,0,99);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Long\t|\t " << merge_time << " us\n";
//// Half-Sorted Tests ////	
	std::cout << "\n\n\n\tHalf-Sorted\n\nLength\t|\tMerge\n";
	time.start();
	recursive(short_half,0,9);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Short\t|\t " << merge_time << " us\n";

	time.start();
	recursive(medium_half,0,49);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Medium\t|\t " << merge_time << " us\n";

	time.start();
	recursive(long_half,0,99);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Long\t|\t " << merge_time << " us\n";

//// Reverse Sorted Tests /////
	std::cout << "\n\n\n\tReverse Sorted\n\nLength\t|\tMerge\n";
	time.start();
	recursive(short_reverse,0,9);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Short\t|\t " << merge_time << " us\n";

	time.start();
	recursive(medium_reverse,0,49);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Medium\t|\t " << merge_time << " us\n";

	time.start();
	recursive(long_reverse,0,99);
	time.stop();
	merge_time = time.get_time_micro();
	std::cout << "Long\t|\t " << merge_time << " us\n\n\n";
}
