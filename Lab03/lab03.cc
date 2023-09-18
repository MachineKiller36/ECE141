#include <iostream>
//// Selection Sort Algorithm ////
/*
        Parameters:
                array size and the array itself.

        How it works:

 */
void selection(int size, int data[]) {
        for(int index = 0; index < size-1; index++) {
                int smallest = index;
                for(int position = index+1; position < size; position++) {
                        if(data[position] < data[smallest]) {
                                smallest = position;
                        }
                }
                int temp = data[index];
                data[index] = data[smallest];
                data[smallest] = temp;
        }
}

//// Selection Sort Algorithm ////
/*
        Parameters is the array size and the array itself.
 */
void bubble(int size, int data[]) {
        for(int index = 0; index< size; index++) {
                for(int position = size; position > index; position--) {
                        if(data[position] < data[position-1]) {
                                int temp = data[position];
                                data[position] = data[position-1];
                                data[position-1] = temp;
                        }
                }
        }
}

int main() {
	
}
