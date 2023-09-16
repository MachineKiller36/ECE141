#include <iostream>
#include "Timer.h"
#include "Colors.h"
#include <fstream>
#include <string>
#include <vector>

/*
	 Purpose of the function is to compute the fibnocci sequence for a number, quickly
  How it works: It caches any new computations and uses previously computation instead of
                recomputing it. The flaw of slowFib is it repeatedly redoes the same computations.
 */
// Pre allocated results inside a cache
std::vector<uint64_t> cache = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181 };
uint64_t fastfib(uint64_t number) {
	if(number < cache.size()) return cache[number];                 // Checks if the number has already been computed and returns the value from the cache.
	uint64_t result = fastfib(number-1) + fastfib(number-2);     	// If the value is not inside the cache it calls fastfib twice and add their results together.
	cache.push_back(result);                      	                // Once the problem has been computed it stores it in the cache
	return result;                               	                // Returns the result
}


/*
 	Purpose of the function is to compute the fibnocci sequence for a number, slowly.
 */
int slowfib(int number) {
	if(number <= 1) return number;			 		// Returns 1 if the number is less or equal to 1 and functions
	return slowfib(number-1)+slowfib(number-2);      		// Calls slowfib twice 
}

int main() {
	Timer time;                                     		// Creates a timer named time from the header "Timer.h"
	time.clear_file("slowfib.txt");                 		// Clears slowfib.txt
	time.clear_file("fastfib.txt");					// Clears fastfib.txt
	
	//// User Interface //////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	 * 	Purpose: Is to allow the user to test individual values
	 */
	while(true) {
		std::cout << "\nPlease enter a positive integer to calculate its fibnocci sequence\n or enter a negative to quit\n > ";
		int user_input = 0;
		std::cin >> user_input;					// Takes in user input
		if(user_input < 0) break;				// If less than 0 it ends the loop
		std::cout << "\n Slowfib: ";				
		time.start();						// Takes the start point
		std::cout << slowfib(user_input);			// Calls slowFib with the user's input as a parameter
		time.stop();						// Takes the end point
		std::cout << "\t";					
		time.print_screen();					// Print the time results on the terminal screen for slowFib

		std::cout << "\n Fastfib: ";
		time.start();						// Takes the start point
		std::cout << fastfib(user_input);			// Call fastFib with the user's input as a parameter
		time.stop();						// Takes the end point
		std::cout << "\t";
		time.print_screen();					// Prints the time results on the terminal screen for fastFib
	}
	
	//// Test Benching //////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	 * 	Purpose: Is to better highlight the timing differences between the two implementations of Fibonacci's sequence.
	 */
	std::cout << "\t\tCOMPARISON\nNumber: |\tSlowfib |\tFastfib |\tTimescale: microseconds\n\n";
	std::vector<int> iterator;					// Stores the iterators called
	std::vector<double> slowFibResults;				// Stores the slowFib timing results
	std::vector<double> fastFibResults;				// Stores the fastFib timing results
	
	for(int i = 0; i < 50; i++) {  
		iterator.push_back(i);					// Adds i to the iterator vector
		std::string number = std::to_string(i); 		// Convert the iterator to string in order to output it into a text file
		
		/// Slowfib Test //////////////////////////////
		/*
		 *  Uses "Timer.h" header to do timing of the function
		 */
		time.start();                   			// Takes the start point
		slowfib(i);                     			// Calls slowfib with the iterator as a parameter 
		time.stop();                    			// Takes the end timepoint
		time.print_file("slowfib.txt", number); 		// Stores the time breakdown in text file "slowfib.txt"
		double slowFibTime = time.get_time_micro();		// Stores the time in Microseconds in slowFibTime
		slowFibResults.push_back(slowFibTime);			// Adds slowFibTime to the vector slowFibResults
		
		/// Fastfib Test ///////////////////////////////
		/*
		 *  Uses "Timer.h" header to do timing of the function
		 */
		time.start();                                 		// Takes the start point.
		fastfib(i);                                     	// Calls fastfib with the iterator as a parameter.
		time.stop();						// Takes the end point. 
		time.print_file("fastfib.txt", number);			// Stores the time breakdown in text file "fastfib.txt"
		double fastFibTime = time.get_time_micro();		// Stores the time in Microseconds in fastFibTime
		fastFibResults.push_back(fastFibTime);			// Adds fastFibTime to the vector fastFibResults
		
		/// Comparison Section ///////////////////////
		/* 
		 *	Prints results only to the terminal screen.
		 *
		 *	It compares the time results stored in slowTime and fastTime.
		 *	The smaller time text color is set to green. 
		 *	The bigger time text color is set to red.
		 *	If it is a draw, the color remains white.
		 *
		 *	The color options is added by the header "Colors.h"
		 *
		 *	Purpose: Is to have a better visual indicator of the time differences
		 */
		std::cout << i << "\t";
		if(slowFibTime > fastFibTime) {
			std::cout << RED << slowFibTime << RESET << "\t" << GREEN << fastFibTime << RESET << "\n";
		} else if(slowFibTime < fastFibTime){
			std::cout << GREEN << slowFibTime << RESET << "\t" << RED << fastFibTime << RESET << "\n";
		} else {
			std::cout << slowFibTime << "\t" << fastFibTime << "\n";
		}
	}
	//// Load Results into Text //////////////////////////////////////////////////////////////////////////////////////////////
	/*
	 * 	Purpose: Is to provide an easy copy and paste version of the timing results.
	 */
	std::ofstream results("results.txt",std::ofstream::trunc);	// Creates a text file named "results.txt" and clears the file
	results << "Iterator:\n";	
	for(int i = 0; i < iterator.size(); i++) {			
		results << iterator[i] << " ";				// Print all the stored numbers tested into the file
	}
	results << "\n\nSlowfib Results:\n";
	for(int i = 0; i < slowFibResults.size(); i++) {
		results << slowFibResults[i] << " ";			// Prints all the slowFib times into the file
	}
	results << "\n\nFastfib Results:\n";
	
	for(int i = 0; i < fastFibResults.size(); i++) {
		results << fastFibResults[i] << " ";			// Prints all the fastFib times into the file
	}
}
