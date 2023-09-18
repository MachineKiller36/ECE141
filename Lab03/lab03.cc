#include <iostream>

void selection(int size, int data[]) {
	for(int index = 1; index < size; index++) {
		int element = data[index];
		int position = index-1;
		while(position > -1 && element < data[position]) {
			data[position+1] = data[position];
			position--;
		}
		data[position+1] = element;
	}
}

void bubble(int size, int data[]) {
	bool notDone = true;
	while(notDone) {
		notDone = false;
		for(int index = 0; index < size; index++) {
			if(data[index] > data[index+1]) {
				notDone = true;
				int temp = data[index+1];
				data[index+1] = data[index];
				data[index] = temp;
			}
		}
	}
}

int main() {
	
}
