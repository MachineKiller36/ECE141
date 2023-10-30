#include <iostream>
#include <string>
#include <fstream>
#include "Timer.h"

#define HASHSIZE 4001
int cstoi(std::string convert_string) {
	// T(n) = LENGTH[convert_string]
	int size = convert_string.length();				// Gets length of the string
	int sum = 0;							// Holds the summed value of each character in the string
	for(int i = 0; i < size; i++) {					// Iterates through the string, adding the integer value of every character into sum
		sum += convert_string[i];
	}
	return sum;							// Returns the summed value
}
class Hash {
	public:
		Hash(size_t new_capacity) {
			// T(n) = k
			m_capacity = new_capacity;			// Sets the capacity to the new size
			m_data = new std::string[m_capacity];		// Creates an array of strings
			for(int i = 0; i < m_capacity; i++)		// Iterates through the hash clear each element
				m_data[i] = "";
		}
		~Hash() {}
		void insert(std::string new_string) {
			// Best case: 1
			// Worst case: k	<-- Occurs when there is exactly one spot left
			if(m_size >= m_capacity) {			// Checks if the hash is full
				std::cout << "Overflow!\n";
				return;
			}
			int index = cstoi(new_string);			// Converts string into an integer
			index = index % m_capacity;			// Finds index in hash
			while(m_data[index] != "") {			// Iterates until it finds an open spot in the hash
				index++;
				if(index >= m_capacity) index = 0;	// Puts index at the beginning of the hash if the index has reached the end
			}
			m_data[index] = new_string;			// Places element into the hash at the index
			m_size++;					// Increments the size
		}
		void remove(std::string new_string) {
			// Best case: 1		  
			// Worst case: k           <-- Occurs when either the element is the index before its initial placement or when the element does not exist
			if(m_size < 1) {				// Checks if hash is empty
				std::cout << "Underflow!\n";
				return;
			}
			int index = cstoi(new_string);			// Convert string into an integer
			index = index % m_capacity;			// Finds index in hash
			int break_cond = m_capacity;			// Prevents from infinitely looping if the element does not exist
			while(m_data[index] != new_string) {		// Iterates until it finds the desired element or it has gone through the whole hash
				index++;
				if(index >= m_capacity) index = 0;	// Puts index at the beginning of the hash if the index has reached the end 
				if(!break_cond) return;			// Returns if the element does not exist
				break_cond--;
			}
			m_data[index] = "";				// Clears the hash at the index
			m_size--;					// Decrements the size
		}
		void print() {
			// T(n) = k
			for(int i = 0; i < m_capacity; i++)		// Iterates through the hash printing all the elements
				std::cout << "Index: " << i << "\t" << m_data[i] << "\n";
		}
		size_t capacity() const { return m_capacity; }
		size_t size() const { return m_size; }
	private:
		std::string* m_data;					// Points to the array of string
		size_t m_capacity = 0;					// Symbol: k, holds the maximum size of the hash
		size_t m_size = 0;					// Symbol: n, holds the number of elements currently in the hash
		
};

int main() {
////////////////////////	USER INTERFACE	//////////////////////////
	Timer time;
	Hash hash(5);
	while(true) {
		std::cout << "\n\n\nSize of hash: " << hash.size() << "\t|\tCapacity of hash: " << hash.capacity() << "\n\n";
		std::cout << "Current hash:\n";
		hash.print();
		std::cout << "\nTo insert a element enter '1' or to remove a element enter '0'\n\t! Anything else will quit program !\n > ";
		std::string user_action = "a";
		std::cin >> user_action;
		if(user_action != "1" && user_action != "0") break;
		if(user_action == "1") {
			std::cout << "\nEnter a string to insert:\n > ";
			std::string user_string = "a";
			std::cin >> user_string;
			time.start();
			hash.insert(user_string);
			time.stop();
			time.print_screen("\nInserted an element into the Hash:");
		} else {
			std::cout << "\nEnter a string to remove:\n > ";
			std::string user_string = "a";
			std::cin >> user_string;
			time.start();
			hash.remove(user_string);
			time.stop();
			time.print_screen("\nRemoved an element from the Hash:");
		}
	}
/////////////////////	FILE PASING	////////////////////////
	Hash file_hash(HASHSIZE);
	
}
