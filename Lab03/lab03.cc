#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Timer.h"
//// Selection Sort Algorithm ////
/*
        Parameters:
                array size and the array itself.

        How it works:
                1. Finds the smallest element in the array
                2. Then it swaps with the element in the first position
                3. Next, if finds the second smallest element and swaps the elements in position two
                4. Repeats until the array is sorted


        Asymptotic Analysis:
                Best case:    Ω( n^2 )
                Average case: Θ( n^2 )
                Best case:    O( n^2 )
 */
void selection(int size, long long int data[]) {
        for(int index = 0; index < size; index++) {                             // Iterates through all elements
                int smallest = index;                                           // Sets the index to smallest
                for(int position = index+1; position < size; position++) {      // Iterates through all
                        if(data[position] < data[smallest]) {                   // If the data at positions index is then data at smallests index
                                smallest = position;                            // Sets smallest equal to position
                        }
                }
                long long int temp = data[index];                                // Temporary variable to hold data at index values
                data[index] = data[smallest];                                   // Sets data at index with the value at data smallest
                data[smallest] = temp;                                          // Sets data at smallest with temporary variable
        }
}

//// Selection Sort Algorithm ////
/*
        Parameters:
                array size and the array itself.

        How it works:
                1. Iterates over all elements
                2. Swaps each element with the next element if out of order
                3. Repeats until no swaps are needed

        Asymptotic Analysis:
                Best case:    Ω( n )
                Average case: Θ( n^2 )
                Worst case:   O( n^2 )
 */
void bubble(int size, long long int data[]) {
        for(int i = 1; i < size; i++) {
                for(int j = 0; j < size-1; j++) {
                        if(data[j] > data[j+1]) {
                                long long int temp = data[j];
                                data[j] = data[j+1];
                                data[j+1] = temp;
                        }
                }
        }
}

int main() {
        Timer time;
        //// User Interface ///////////
        while(true) {
                std::cout << "Enter the size of the array you want to test:\n\t! Entering a negative or a zero stops manual input section !\n> ";         // Prompts User
                int user_size = 0;
                std::cin >> user_size;    // Takes in user input                                                                                  
                if(user_size < 1) break;  // Exits user interface if input is less than 1

                long long int user_array[user_size];      // Creates an array with user defined size
                long long int user_array_2[user_size];    // Creates an array with user defined size

                std::cout << "Enter a positive value to manual input elements or enter a negative to randomize inputs:\n > ";  // Prompts user
                int user_choice = 0;
                std::cin >> user_choice;     // Takes in user input

                if(user_choice < 0) {
                        std::srand(std::time(0));  // Prevents duplicates
                        for(int index = 0; index < user_size; index++) {
                                // Generates random value and stores it in the arrays
                                long long int value = (std::rand() & 1000) + 1;
                                user_array[index] = value;
                                user_array_2[index] = value;
                        }
                } else {
                        for(int index = 0; index < user_size; index++) {
                                std::cout << "Enter a value for the array at index " << index << "\n > "; // Prompts the user
                                long long int user_element = 0;
                                std::cin >> user_element;             // Takes in user input
                                user_array[index] = user_element;     //  Inserts input into the array
                                user_array_2[index] = user_element;   // Inserts input into the array
                        }
                }
                std::cout << "User array:\n";
                for(int index = 0; index < user_size; index++) {
                        std::cout << user_array[index] << "\t";      // Prints unmodified array
                }
                std::cout << "\n\nSelection sort:\n";
                time.start();                                        // Takes start time
                selection(user_size,user_array);                     // Array 1 undergoes selection sort
                time.stop();                                         // Takes end time
                time.print_screen();                                 // Prints time results

                std::cout << "\nBubble sort:\n";
                time.start();                                        // Takes start time
                bubble(user_size, user_array_2);                     // Array 2 undergoes bubble sort
                time.stop();                                         // Takes end time
                time.print_screen();                                 // Prints time results
                
                std::cout << "Selection sort resulting array:\n";
                for(int index = 0; index < user_size; index++) {
                        std::cout << "\t" << user_array[index];      // Prints list order thats under went selection sort
                }
                std::cout << "\nBubble sort resulting array:\n";
                for(int index = 0; index < user_size; index++) {
                        std::cout << "\t" << user_array_2[index];   // Prints list order thats under went bubble sort
                }
                std::cout << "\n\n\n\n\n\n\n";                      // "Clears" terminal screen
        }

        //// Test Bench ////
}
