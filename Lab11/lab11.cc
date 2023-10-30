#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bst.h"
#include "Timer.h"

void print_array(int* array, int size) {
	for(int i = 0; i < size; i++)
		std::cout << array[i] << "\t";
	std::cout << "\n";
}

int main() {
	srand(time(0));
	bst<int> tree;
	////////////////	USER INTERFACE		/////////////////
	while(true) {
		std::cout << "\n\n\nEnter the size of the array you want to create.\n\t! zero or negative quits the user interface !\n > ";
		int user_size = 0;
		std::cin >> user_size;
		if(user_size <= 0 ) break;
		int user_array[user_size];

		std::cout << "Enter a positive value to randomize the value or a zero or negative value to manually input values:\n > ";
		int user_choice = 0;
		std::cin >> user_choice;
		if(user_choice > 0) {
			for(int i = 0; i < user_size; i++) {
				int random_value = (rand() % user_size) + 1;
				user_array[i] = random_value;
				tree.insert(random_value);
			}
		} else {
			for(int i = 0; i < user_size; i++) {
				std::cout << "Enter a element into the array.\nIndex " << i << ":\t";
				int user_value = 0;
				std::cin >> user_value;
				user_array[i] = user_value;
				tree.insert(user_value);
			}
		}

		std::cout << "Inserted elements: ";
		print_array(user_array, user_size);

		std::cout << "\nPost-order: ";
		tree.print();					// TODO: Print is no working AND might not be whats wanted
		std::cout << "\n";

		std::cout << "\nLargest element in the list is: " << tree.max() << "\n";

		std::cout << "\nInsert a number for look up >> ";
		int search_value = 0;
		std::cin >> search_value;
		if(tree.find(search_value)) {
			std::cout << search_value << " is found\n";
		} else {
			std::cout << search_value << " is a not member of the list/ " << search_value << " not found\n";
		}

		std::cout << "\nInsert a number for look up >> ";
		std::cin >> search_value;
		if(tree.find(search_value)) {
			std::cout << search_value << " is found\n";
		} else {
			std::cout << search_value << " is a not member of the list/ " << search_value << " not found\n";
		}
	}
	///////////////	    END OF USER INTERFACE 	///////////////////
}
