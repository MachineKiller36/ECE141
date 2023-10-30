#ifndef TIMER_H
#define TIMER_H
#pragma once
#include <chrono>      // Used to take time points
#include <fstream>     // Used to output to a text file
#include <iostream>    // Used to output results to the terminal
#include <string> // Used over std::string because it does not put any string greater than 15 characters on the heap
#include <vector>      // Used to print a set of data
/*
        Documentation:
                - The purpose of this library is to be an easy to use timer without having to use std::chrono. 
                - The downside of std::chrono is how verbose it is, so by using this library it will alleviate this issue.
                - Printing functions were added for the sake of convience. You can implement your own result recording systems
                  in your code, but to make it easier pre-made ones where included.

        !!! 
            Warning: Before using the get_time and print functions make sure you called start() and stop(),
                               otherwise it will not work.
            Reason: It was implement this to give user a higher degree of control, but comes at a risk.
         !!!
*/
class Timer {
        public/* methods*/:
                Timer();
                ~Timer();
                void start();                                     // Sets the m_startpoint to current time
                void stop();                                      // Sets the m_endpoint to current time
		double get_time_nano();				  // Returns the nanoseconds difference between the end and start points
                double get_time_micro();                          // Returns the microseconds difference between the end and start points 
                double get_time_milli();                          // Returns the milliseconds difference between the end and start points
		// Parameters: "File Name", "Marker" 
                // "Marker" can be omitted
                void print(const char*, std::string);        // Prints the time difference in the terminal and in a text file
                // Parameter: "Marker"
                // "Marker" can be omitted
                void print_screen(std::string);              // Prints the time difference in the terminal;
                // Parameters: "File Name", "Marker"
                // "Marker" can be omitted
                void print_file(const char*, std::string);   // Prints the time difference in a text file
                // Parameters: "File Name", "Message", "Data", "Data Markers"
                // "Message", "Data", "Data Marker" can be omitted
                void write_file(const char*, std::string); // Prints additonal info to a text file
                void clear_file(const char*); // Used to clear a text file of choice
        private/* members */:
                std::chrono::time_point<std::chrono::high_resolution_clock> m_StartPoint;
                std::chrono::time_point<std::chrono::high_resolution_clock> m_EndPoint;
};
/*
        Example:
        _______ Example.cpp ______________________________________________________________
        |       #include <iostream>                                                      |
        |       #include Timer.h                                                         |
        |                                                                                |
        |        int main() {                                                            |
        |                Timer time;                                                     |
        |                time.start();                                                   |
        |                for(int i = 10; i > -1; i--)                                    |
        |                         std::cout << i << " ";                                 |
        |                time.stop();                                                    |
        |                std::cout << time.get_time_micro() << " microseconds\n";        |
        |                std::cout << time.get_time_milli() << " milliseconds\n";        |
        |                time.print("result.txt", "Overall ");                           |
        |        }                                                                       |
        |________________________________________________________________________________|
        _______ Terminal _________________________________________________________________
        |     path:~/dir$ g++ ex.cc -O3                                                  |
        |     10 9 8 7 6 5 4 3 2 1 0                                                     |
        |     44 microseconds                                                            |
        |     0.044 milliseconds                                                         |
        |     Overall | Time Taken: 44 μs | 0.044 ms                                     |
        |________________________________________________________________________________|
        _______ result.txt _______________________________________________________________
        |                                                                                |
        |     Overall | Time Taken: 44 μs | 0.044 ms                                     |
        |                                                                                |
        |________________________________________________________________________________|

*/
inline Timer::Timer() {}
inline Timer::~Timer() {}

inline void Timer::start() {
        m_StartPoint = std::chrono::high_resolution_clock::now();
}
inline void Timer::stop() {
        m_EndPoint = std::chrono::high_resolution_clock::now();
}
inline double Timer::get_time_nano() {
        auto start_nano_seconds = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartPoint).time_since_epoch().count();
        auto end_nano_seconds   = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_EndPoint).time_since_epoch().count();
        return end_nano_seconds - start_nano_seconds;
}
inline double Timer::get_time_micro() {
        return get_time_nano() * 0.001;
}

inline double Timer::get_time_milli() {
        return get_time_micro() * 0.001;
}

inline void Timer::print(const char* file_name, std::string message = "") {
        double nanoseconds	 = get_time_nano();
	double microseconds 	 = nanoseconds * 0.001;
	double milliseconds      = microseconds * 0.001;
       	std::cout << message << "\t| Time Taken:\t" << nanoseconds << " ns\t | " << microseconds << " μs | " << milliseconds << " ms\n";
        std::ofstream file(file_name, std::ios_base::app);
        file << message << "\t| Time Taken:\t" << nanoseconds << " ns\t | " << microseconds << " μs | " << milliseconds << " ms\n";
        file.close();
}

inline void Timer::print_screen(std::string message = "") {
        double nanoseconds	 = get_time_nano();
	double microseconds 	 = nanoseconds * 0.001;
	double milliseconds      = microseconds * 0.001;
       	std::cout << message << "\t| Time Taken:\t" << nanoseconds << " ns\t | " << microseconds << " μs | " << milliseconds << " ms\n";
}

inline void Timer::print_file(const char* file_name, std::string message = "") {
        double nanoseconds	 = get_time_nano();
	double microseconds 	 = nanoseconds * 0.001;
	double milliseconds      = microseconds * 0.001;
        std::ofstream file(file_name, std::ios_base::app);
        file << message << "\t| Time Taken:\t" << nanoseconds << " ns\t | " << microseconds << " μs | " << milliseconds << " ms\n";
        file.close();
}

inline void Timer::write_file(const char* file_name, std::string message = "") {
        std::ofstream file(file_name, std::ios_base::app);
        file << message << "\n\t";
        file.close();
}

inline void Timer::clear_file(const char* file_name) {
        std::ofstream file(file_name, std::ofstream::trunc);
        file.close();
}
#endif
