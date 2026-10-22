int heap[1000];
int size = 0;
int diff = 0;

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        index = largest;
    }
}

void insert(int value) {
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

int delete() {
    if (size == 0) {
        return -1;
    }
    int deleted = heap[0];

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapifyDown(0);

    return deleted;
}

int lastStoneWeight(int* stones, int stonesSize) {
    size = 0;
    for (int i =0; i <stonesSize; i++) {
        insert(stones[i]);
    }

    while (size>1) {
        int firstmax = delete();
        int secondmax = delete();

        if (firstmax != secondmax) {
            diff = firstmax - secondmax;
            insert(diff);
        }
        
    }
    if (size == 0) return 0;

    return heap[0];
}