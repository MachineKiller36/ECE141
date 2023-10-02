class Heap {
	private /* members */:
		int* Arr;
		int size = 0;
		int capacity = 0;
	public:
		Heap(int);
		~Heap();
		void printArray();
		// Max Heap Functions //
		void max_heapify(int, int);
		void modifyValMax(int, int);
		void buildMaxHeap();
		void insert_value_maxHeap(int);
		int extract_maximum();
		void ascendingHeapSort();

		// Min Heap Functions //
		void min_heapify(int, int);
		void modifyValMin(int, int);
		void buildMinHeap();
		void insert_value_minHeap(int);
		int extract_minimum();
		void descendingHeapSort();
};

inline Heap::Heap(int new_size) {
	Arr = new int[new_size];
	capacity = new_size;
}
inline Heap::~Heap() {
	size = capacity = 0;
}
inline void Heap::printArray() {
	for(int index = 0; index < size; index++) 
		std::cout << Arr[index] << " ";
	std::cout << "\n";
}
//// Maximum Heap Functions ////
inline void Heap::max_heapify(int index, int n) {
	int largest_index = index;
	int left_index = 2*index+1;
	int right_index = 2*index+2;
	if(left_index < n && Arr[left_index] > Arr[largest_index])
		largest_index = left_index;
	if(right_index < n && Arr[right_index] > Arr[largest_index])
		largest_index = right_index;
	if(largest_index != index) {   
		std::swap(Arr[index],Arr[largest_index]);
		max_heapify(largest_index,size);
	}
}

inline void Heap::buildMaxHeap() {
	for(int it = (size/2)-1; it >= 0; it--) {
		max_heapify(it,size);			
	}
}

inline void Heap::modifyValMax(int index, int key) {
	if(index > size-1 || index < 0)
		throw std::runtime_error("Invalid index\n");
	Arr[index] = key;
	buildMaxHeap();
}

inline void Heap::insert_value_maxHeap(int key) {
	if(size >= capacity)
		throw std::runtime_error("Heap is full");
	Arr[size] = key;
	size++;
	buildMaxHeap();
}

inline int Heap::extract_maximum() {
	if(size < 1)
		throw std::runtime_error("Heap is empty!\n");
	int max = Arr[0];
	size--;
	Arr[0] = Arr[size];
	max_heapify(0,size);					
	return max;
}

inline void Heap::ascendingHeapSort() {
	buildMaxHeap();
	for(int it = size-1; it >= 0; it--) {
		std::swap(Arr[0],Arr[it]);
		max_heapify(0,it);
	}
}
//// Minimum Heap Functions ////
inline void Heap::min_heapify(int index, int n) {
	int smallest_index = index;
	int left_index = 2*index+1;
	int right_index = 2*index+2;
	if(left_index < n && Arr[left_index] < Arr[smallest_index])
		smallest_index = left_index;
	if(right_index < n && Arr[right_index] > Arr[smallest_index])
		smallest_index = right_index;
	if(smallest_index != index) {   
		std::swap(Arr[index],Arr[smallest_index]);
		min_heapify(smallest_index,size);
	}
}

inline void Heap::buildMinHeap() {
	for(int it = (size/2)-1; it >= 0; it--) {
		min_heapify(it,size);			
	}
}

inline void Heap::modifyValMin(int index, int key) {
	if(index > size-1 || index < 0)
		throw std::runtime_error("Invalid index\n");
	Arr[index] = key;
	buildMinHeap();
}

inline void Heap::insert_value_minHeap(int key) {
	if(size >= capacity)
		throw std::runtime_error("Heap is full");
	Arr[size] = key;
	size++;
	buildMinHeap();
}

inline int Heap::extract_minimum() {
	if(size < 1)
		throw std::runtime_error("Heap is empty!\n");
	int min = Arr[0];
	size--;
	Arr[0] = Arr[size];
	min_heapify(0,size);					
	return min;
}

inline void Heap::descendingHeapSort() {
	buildMinHeap();
	for(int it = size-1; it >= 0; it--) {
		std::swap(Arr[0],Arr[it]);
		min_heapify(0,it);
	}
}
