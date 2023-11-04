#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

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
			m_data = new std::pair<std::string,int>[m_capacity]; // Creates an array of strings
			m_probe = new double[m_capacity];
			m_update = new double[m_capacity];
			for(int i = 0; i < m_capacity; i++) {		// Iterates through the hash clear each element
				m_data[i].first = "";
				m_data[i].second = 0;
				m_probe[i] = 0;
				m_update[i] = 0;
			}
		}
		~Hash() {}
		int insert(std::string new_string) {
			// Best case: 1
			// Worst case: k	<-- Occurs when there is exactly one spot left
			if(m_size >= m_capacity) {			// Checks if the hash is full
				std::cout << "Overflow!\n";
				return 0;
			}
			int index = cstoi(new_string);			// Converts string into an integer
			index = index % m_capacity;			// Finds index in hash
			int access_count = 0;
			while(m_data[index].first != "" && m_data[index].first != new_string) {			// Iterates until it finds an open spot in the hash
				m_probe[index]++;
				index++;
				access_count++;
				if(index >= m_capacity) index = 0;	// Puts index at the beginning of the hash if the index has reached the end
			}	
			if(m_data[index].first == new_string) {
				m_data[index].second++;
			} else {
				m_data[index].first = new_string;		// Places element into the hash at the index
				m_data[index].second++;
				m_size++;
			}
			m_word_count++;
			m_update[index]++;
			m_total_update++;
			m_total_probe += access_count;
			return access_count;
		}
		int remove(std::string removed_string) {
			// Best case: 1		  
			// Worst case: k           <-- Occurs when either the element is the index before its initial placement or when the element does not exist
			if(m_size < 1) {				// Checks if hash is empty
				std::cout << "Underflow!\n";
				return 0;
			}
			int index = cstoi(removed_string);			// Convert string into an integer
			index = index % m_capacity;			// Finds index in hash
			int break_cond = m_capacity;			// Prevents from infinitely looping if the element does not exist
			int access_count = 0;
			while(m_data[index].first != removed_string) {		// Iterates until it finds the desired element or it has gone through the whole hash
				m_probe[index]++;
				access_count++;
				index++;
				if(index >= m_capacity) index = 0;	// Puts index at the beginning of the hash if the index has reached the end 
				if(!break_cond) return access_count;			// Returns if the element does not exist
				break_cond--;
			}
			if(--m_data[index].second == 0) {
				m_data[index].first = "";				// Clears the hash at the index
				m_size--;						// Decrements the size]
			}
			m_word_count--;
			m_update[index]++;
			m_total_update++;
			m_total_probe += access_count;
			return access_count;
		}
		void print() {
			// T(n) = k
			for(int i = 0; i < m_capacity; i++) {		// Iterates through the hash printing all the elements
				if(m_data[i].first != "")
					std::cout << "Index: " << i << "\t\tString: " << m_data[i].first << "\t\tCount: " << m_data[i].second << "\n";
			}
		}
		size_t capacity() const   { return m_capacity; }
		size_t size() const       { return m_size; }
		size_t word_count() const { return m_word_count; }
		size_t total_probes() const { return m_total_probe; }
		size_t total_updates() const { return m_total_update; }
		double* probes() const    { return m_probe; }
		double* updates() const   { return m_update; }
	private:
		std::pair<std::string,int>* m_data;			// Points to the array of string
		size_t m_capacity = 0;					// Symbol: k, holds the maximum size of the hash
		size_t m_size = 0;					// Symbol: n, holds the number of unique elements currently in the hash
		size_t m_word_count = 0;				// Number of elements inserted
		size_t m_total_probe = 0;				// Total number of probes
		size_t m_total_update = 0;				// Total number of updates
		double* m_probe;					// Array holding the number of probes at each index
		double* m_update;					// Array holding the number of updates at each index
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
			std::cout << "\nNumber of accesses: " << hash.insert(user_string) << "\n";
			time.stop();
			time.print_screen("\nInserted an element into the Hash:");
		} else {
			std::cout << "\nEnter a string to remove:\n > ";
			std::string user_string = "a";
			std::cin >> user_string;
			time.start();
			std::cout << "\nNumber of accesses: " << hash.remove(user_string) << "\n";
			time.stop();
			time.print_screen("\nRemoved an element from the Hash:");
		}
	}
/////////////////////	FILE PASING	////////////////////////
	Hash file_hash(HASHSIZE);
	std::ifstream file("RomeoAndJuliet.txt");
	std::string file_word = "";
	while(file >> file_word) {
		file_hash.insert(file_word);
	}
	std::cout << "Number of unique words: " << file_hash.size() << "\t\tWord count: " << file_hash.word_count() << "\n";
	std::cout << "Total number of updates: " << file_hash.total_updates() << "\t\tTotal number of probes: " << file_hash.total_probes() << "\n";	
	double* updates = file_hash.updates();
	double* probes = file_hash.probes();
	for(int i = 0; i < file_hash.capacity(); i++) {
		double ratio = 0.00;
		if(updates[i] > 0) {
			ratio = probes[i]/updates[i];
		}
		std::cout << std::setprecision(2) << std::fixed << ratio << ",\t";
		if(i % 10 == 0) std::cout << "\n";
	}
	std::cout << "\n";
}
