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
 */
void selection(int size, int data[]) {
        for(int index = 0; index < size; index++) {                             // Iterates through all elements
                int smallest = index;                                           // Sets the index to smallest
                for(int position = index+1; position < size; position++) {      // Iterates through all
                        if(data[position] < data[smallest]) {                   // If the data at positions index is then data at smallests index
                                smallest = position;                            // Sets smallest equal to position
                        }
                }
                int temp = data[index];                                         // Temporary variable to hold data at index values
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
 */
void bubble(int size, int data[]) {
        for(int i = 1; i < size; i++) {                                         // Iterates though its size starting at 1
                for(int j = 0; j < size-1; j++) {                               // Iterates through the array again 
                        if(data[j] > data[j+1]) {                               // Checks if next spot in array is less than the curren spot
                                int temp = data[j];                             //
                                data[j] = data[j+1];                            //  Swaps spots
                                data[j+1] = temp;                               //
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

                int user_array[user_size];      // Creates an array with user defined size
                int user_array_2[user_size];    // Creates an array with user defined size

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
                                int user_element = 0;
                                std::cin >> user_element;             // Takes in user input
                                user_array[index] = user_element;     //  Inserts input into the array
                                user_array_2[index] = user_element;   // Inserts input into the array
                        }
                }
                if(user_size < 50) {
                        std::cout << "User array:\n";
                        for(int index = 0; index < user_size; index++) {
                                std::cout << user_array[index] << "\t";
                        }
                }
                std::cout << "\n\nSelection sort:\n";
                time.start();
                selection(user_size,user_array);
                time.stop();
                time.print_screen();

                std::cout << "\nBubble sort:\n";
                time.start();
                bubble(user_size, user_array_2);
                time.stop();
                time.print_screen();
                if(user_size < 50) {
                        std::cout << "\n\nSelection sort resulting array:\n";
                        for(int index = 0; index < user_size; index++) {
                                std::cout << "\t" << user_array[index];
                        }
                        std::cout << "\nBubble sort resulting array:\n";
                        for(int index = 0; index < user_size; index++) {
                                std::cout << "\t" << user_array_2[index];
                        }
                }
                std::cout << "\n\n\n\n\n\n\n";
        }
        //// Test Bench ////
                //// Test Arrays ////
        int short_sorted_select[10];
        int short_sorted_bubble[10];
        int short_half_select[10];
        int short_half_bubble[10];
        int short_reverse_select[10];
        int short_reverse_bubble[10];

        int medium_sorted_select[50];
        int medium_sorted_bubble[50];
        int medium_half_select[50];
        int medium_half_bubble[50];
        int medium_reverse_select[50];
        int medium_reverse_bubble[50];

        int long_sorted_select[100];
        int long_sorted_bubble[100];
        int long_half_select[100];
        int long_half_bubble[100];
        int long_reverse_select[100];
        int long_reverse_bubble[100];
        // Fills Sorted Arrays //
        for(int i = 0; i < 100; i++) {
                if(i < 10) {
                        short_sorted_select[i] = i;
                        short_sorted_bubble[i] = i;
                }
                if(i < 50) {
                        medium_sorted_select[i] = i;
                        medium_sorted_bubble[i] = i;
                }
                if(i < 100) {
                        long_sorted_select[i] = i;
                        long_sorted_bubble[i] = i;
                }
        }
        // Fills Reverse Sorted Arrays //
        int value1 = 10;
        int value2 = 50;
        int value3 = 100;
        for(int i = 0; i < 100; i++) {
                if(i < 10) {
                        short_reverse_select[i] = value1;
                        short_reverse_bubble[i] = value1;
                }
                if(i < 50) {
                        medium_reverse_select[i] = value2;
                        medium_reverse_bubble[i] = value2;
                }
                if(i < 100) {
                        long_reverse_select[i] = value3;
                        long_reverse_bubble[i] = value3;
                }
                value1--;
                value2--;
                value3--;
        }
        // Fills Half Sorted Arrays //
        value1 = 10;
        for(int i = 0; i < 10; i++) {
                if(i < 5) {
                        short_half_select[i] = i;
                        short_half_bubble[i] = i;
                } else {
                        short_half_select[i] = value1;
                        short_half_bubble[i] = value1;
                        value1--;
                }
        }
        value2 = 50;
        for(int i = 0; i < 50; i++) {
                if(i < 25) {
                        medium_half_select[i] = i;
                        medium_half_bubble[i] = i;
                } else  {
                        medium_half_select[i] = value2;
                        medium_half_bubble[i] = value2;
                        value2--;
                }
        }
                value3 = 100;
        for(int i = 0; i < 100; i++) {
                if(i < 50) {
                        long_half_select[i] = i;
                        long_half_bubble[i] = i;
                } else {
                        long_half_select[i] = value3;
                        long_half_bubble[i] = value3;
                        value3--;
                }
        }
        // Time comparison //
//// Sorted Tests ////
        std::cout << "\n\n\n\t\t\tSorted\n\nLength\t|\tSelection\t|\tBubble\n";
        time.start();
        selection(10,short_sorted_select);
        time.stop();
        double select_time = time.get_time_micro();
        time.start();
        bubble(10,short_sorted_bubble);
        time.stop();
        double bubble_time = time.get_time_micro();
        std::cout << "Short\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";

        time.start();
        selection(50,medium_sorted_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(50,medium_sorted_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Medium\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";
        
        time.start();
        selection(100,long_sorted_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(100,long_sorted_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Long\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";
//// Half-Sorted Tests ////
        std::cout << "\n\n\n\t\t\tHalf-Sorted\n\nLength\t|\tSelection\t|\tBubble\n";
        time.start();
        selection(10,short_half_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(10,short_half_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Short\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";

        time.start();
        selection(50,medium_half_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(50,medium_half_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Medium\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";

        time.start();
        selection(100,long_half_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(100,long_half_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Long\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";
//// Reverse Sorted Tests /////
        std::cout << "\n\n\n\t\t\tReverse Sorted\n\nLength\t|\tSelection\t|\tBubble\n";
        time.start();
        selection(10,short_reverse_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(10,short_reverse_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Short\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";

        time.start();
        selection(50,medium_reverse_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(50,medium_reverse_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Medium\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n";

        time.start();
        selection(100,long_reverse_select);
        time.stop();
        select_time = time.get_time_micro();
        time.start();
        bubble(100,long_reverse_bubble);
        time.stop();
        bubble_time = time.get_time_micro();
        std::cout << "Long\t|\t " << select_time << " us \t|\t " << bubble_time << " us\n\n\n";
}
}
